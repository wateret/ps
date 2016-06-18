n = int(raw_input())
s = 0
for _ in xrange(n):
    x, y = map(float, raw_input().split())
    s += y
print 5 + s/n
