L, R, U, D = 1, 2, 3, 4
n = int(raw_input())
bp = map(int, raw_input().split())
bd = 0
ans = 0
for _ in xrange(n):
    p = map(int, raw_input().split())
    if bp[0] == p[0]:
        d = D if bp[1] < p[1] else U
    else:
        d = L if bp[0] < p[0] else R
    if (bd == U and d == L) or \
       (bd == R and d == U) or \
       (bd == D and d == R) or \
       (bd == L and d == D):
        ans += 1
    bp = p
    bd = d
print ans
