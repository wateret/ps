#!/usr/bin/python

from six.moves import urllib
from six.moves.html_parser import HTMLParser
import os, re

SITE_URL = "http://codeforces.com"
SAVE_DIR = "submissions/"

download_count = 0

TERM_EMPTY = "\033[0m"

def print_yellow(msg):
    TERM_YELLOW = "\033[1;33m"
    print TERM_YELLOW + msg + TERM_EMPTY

def print_red(msg):
    TERM_RED = "\033[1;31m"
    print TERM_RED + msg + TERM_EMPTY

def print_blue(msg):
    TERM_BLUE = "\033[1;34m"
    print TERM_BLUE + msg + TERM_EMPTY

def print_green(msg):
    TERM_GREEN = "\033[1;32m"
    print TERM_GREEN + msg + TERM_EMPTY

def exit_with_msg(msg):
    print_red(msg)
    sys.exit(1)

def get_ext(s):
    ext_dict = {
        "GNU C\+\+\w*" : "cpp",
        "GNU C"        : "c",
        ".*C#.*"       : "cs",
        "Java.*"       : "java",
        "Python.*"     : "py",
        "PyPy.*"       : "py",
        "Haskell.*"    : "java",
    }
    for key in ext_dict:
        if bool(re.match('^%s$' % key, s)):
            return ext_dict[key]
    return "txt"

def input_prompt(msg):
    print msg,
    return raw_input()

def replace_all(repls, str):
    return re.sub('|'.join(re.escape(key) for key in repls.keys()),
                  lambda k: repls[k.group(0)], str)    

def get_next_page_url(page_content):
    FMT_NEXT_PAGE = '<a href="(.*)" class="arrow">&rarr;</a>'
    match = re.search(FMT_NEXT_PAGE, page_content)
    next_page_url = SITE_URL + match.group(1) if match else None
    return next_page_url

def fetch_url_content(url):
    try:
        page = urllib.request.urlopen(url)
    except: # FIXME which exception?
        exit_with_msg("Error while processing : " + url)
    return page.read()

def resolve_lang(s):
    return s.strip()

def resolve_verdict(s):
    return 'Accepted' if s.find('Accepted') else 'Rejected'

def write_source(source, filepath):
    global download_count
    f = open(filepath, 'w')
    f.write(source)
    f.close()
    print_green("file written : %s" % filepath)
    download_count += 1

def download_source(source_url):
    FMT_SOURCE = '<pre class="prettyprint program-source"[^>]*>((?:(?!</pre>).)*)</pre>'
    source_content = fetch_url_content(source_url)
    match = re.search(FMT_SOURCE, source_content, re.DOTALL)
    return HTMLParser().unescape(match.group(1))

def download_page(page_content):
    FMT_TR = '<tr data-submission-id="(\d*)" [^>]*>((?:(?!</tr>).)*)</tr>'
    FMT_TD = '<td[^>]*>((?:(?!</td>).)*)</td>'
    FMT_CONTEST_PROBLEM = '<a href="/problemset/problem/(\w*)/(\w*)">'
    FMT_CONTEST_PROBLEM = '<a href="/problemset/problem/(\w*)/(\w*)">'
    FMT_SOURCE_URL = SITE_URL + "/contest/%s/submission/%s"
    
    records = re.findall(FMT_TR, page_content, re.DOTALL)
    for r in records:
        submission, record = r
        data = re.findall(FMT_TD, record, re.DOTALL)
        raw_problem       = data[3]
        raw_language      = data[4]
        raw_verdict       = data[5]
        contest, problem = re.search(FMT_CONTEST_PROBLEM, raw_problem, re.DOTALL).groups()
        problem_id = contest + problem
        lang = resolve_lang(raw_language)
        verdict = resolve_verdict(raw_verdict)
        filepath = SAVE_DIR + problem_id + '.' + get_ext(lang)
        source_url = FMT_SOURCE_URL % (contest, submission)

        file_exist = os.path.exists(filepath)
        if verdict == 'Accepted' and not file_exist:
            print_blue("download source - %s : %s" % (problem_id, source_url))
            source_content = download_source(source_url)
            write_source(source_content, filepath)
        elif file_exist:
            print_blue("skip duplicate - %s : %s" % (problem_id, source_url))

def main():
    handle = input_prompt("Enter User Handle :")

    if not os.path.exists(SAVE_DIR):
        os.makedirs(SAVE_DIR)

    FMT_FIRST_PAGE_URL = SITE_URL + "/submissions/%s/page/1"
    page_url = FMT_FIRST_PAGE_URL % (handle)
    while page_url is not None:
        print_yellow("work on page : " + page_url)
        page_content = fetch_url_content(page_url)
        download_page(page_content)
        page_url = get_next_page_url(page_content)

    print_yellow("%d files downloaded" % download_count)
    print_yellow("Check out directory - '%s'" % SAVE_DIR)

main()
