n, m, q = map(int, raw_input().split())
A = [[0]*m for _ in xrange(n)]
dr, dc = [0]*n, [0]*m
for _ in xrange(q):
    d = map(int, raw_input().split())
    if d[0] == 1:
        dc[d[1]-1] += 1
    elif d[0] == 2:
        dr[d[1]-1] += 1
    else:
        __, r, c, v = d
        r = (r-1+dr[r-1])%n
        c = (c-1+dc[r-1])%m
        A[r][c] = v
for a in A:
    print ' '.join(map(str, a))
