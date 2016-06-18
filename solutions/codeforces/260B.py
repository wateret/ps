import re
s = raw_input()
month = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
c = {}
regex = re.compile(r'(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[012])-(201[3-5])')
for i in xrange(len(s)):
    m = regex.match(s, i)
    if m:
        r = m.groups()
        if int(r[0]) <= month[int(r[1])]:
            k = '%s-%s-%s' % (r[0], r[1], r[2])
            if k in c:
                c[k] += 1
            else:
                c[k] = 1
print max(c, key=c.get)
