def dist(c1, c2):
    dx, dy = c1[0]-c2[0], c1[1]-c2[1]
    return (dx*dx+dy*dy)**0.5

ax, ay, bx, by, tx, ty = map(float, raw_input().split())
a = [ax, ay]
b = [bx, by]
t = [tx, ty]

n = int(raw_input())
ans = 0.0
A = []
for i in xrange(n):
    A.append(map(float, raw_input().split()) + [i])

def trans(A, c):
    return map(lambda v: [dist(v, c)-dist(v, t), v[2]], A)

if n == 1:
    ans = min(dist(A[0], a), dist(A[0], b)) + dist(A[0], t)
else:
    TA = sorted(trans(A, a))
    TB = sorted(trans(A, b))
    mins = 1e18
    for i in xrange(min(2, n)):
        cv = TB[i][0]
        if TA[0][1] == TB[i][1]:
            cv += min(0.0, TA[1][0])
        else:
            cv += min(0.0, TA[0][0])
        mins = min(cv, mins)
    for i in xrange(min(2, n)):
        cv = TA[i][0]
        if TB[0][1] == TA[i][1]:
            cv += min(0.0, TB[1][0])
        else:
            cv += min(0.0, TB[0][0])
        mins = min(cv, mins)
    ans = 2*sum(map(lambda v: dist(v, t), A)) + mins

print '%.15f' % ans