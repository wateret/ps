from fractions import Fraction
from itertools import *
from operator import *

n = int(raw_input())
L = []
for _ in xrange(n):
    x, y = map(int, raw_input().split())
    L.append((x, y));

O = {}
inf = 0
for pair in combinations(L, 2):
    d = map(sub, pair[1], pair[0])
    try:
        k = (Fraction(d[1], d[0]))
    except ZeroDivisionError:
        k = 'inf'
    key = (d[0]**2+d[1]**2, k)
    try:
        O[key] += 1
    except KeyError:
        O[key] = 1
print sum(map(lambda x: x*(x-1)/2, O.values()))/2
