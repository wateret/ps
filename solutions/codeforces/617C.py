n, x1, y1, x2, y2 = map(int, raw_input().split())

def disq(a, b):
    return (a[0]-b[0])**2+(a[1]-b[1])**2

p = []
for _ in xrange(n):
    r = map(int, raw_input().split())
    r = (disq(r, (x1, y1)), r)
    p.append(r)
p.sort(reverse=True)
ans = 2**63
r2 = 0
for e in p:
    ans = min(ans, e[0]+r2)
    r2 = max(r2, disq(e[1], (x2, y2)))
ans = min(ans, r2)
print ans