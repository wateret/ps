n, m, q = map(int, raw_input().split())
A = [[0]*m for _ in xrange(n)]
Q = []
for _ in xrange(q):
    Q.append(map(int, raw_input().split()))
Q.reverse()

for x in Q:
    if x[0] == 1:
        r = x[1]-1
        A[r] = [A[r][m-1]] + A[r][:m-1]
    elif x[1] == 2:
        c = x[1]-1
        last = A[n-1][c]
        for i in xrange(n-1, 0, -1):
            A[i][c] = A[i-1][c]
        A[0][c] = last
    else:
        __, r, c, v = x
        A[r-1][c-1] = v
for a in A:
    print ' '.join(map(str, a))
