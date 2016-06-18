import re

k = int(raw_input())
s = raw_input()
l = len(s)

if k == 0:
        print sum(map(lambda x: x*(x+1)/2, map(len, (s.split('1')))))
else:
        L = [m.start() for m in re.finditer('1', s)]
        LL = [-1] + L + [l]

        outer = zip(LL[:-(k+1)], LL[k+1:])
        inner = zip(L[:-(k-1)], L[k-1:]) if k > 1 else zip(L, L)
        print sum(map(lambda o, i: (i[0]-o[0])*(o[1]-i[1]), outer, inner))