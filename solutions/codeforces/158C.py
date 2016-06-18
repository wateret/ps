n = int(raw_input())
d = []
for _ in xrange(n):
    q = raw_input()
    if q == 'pwd':
        print('/' + ''.join(map(lambda x: x + '/', d)))
    else:
        _, path = q.split()
        sp = path.split('/')
        for o in sp:
            if o == '':
                d = []
            elif o == '..':
                d.pop()
            else:
                d.append(o)