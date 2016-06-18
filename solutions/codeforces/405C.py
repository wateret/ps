n = int(raw_input())
A = []
for _ in xrange(n):
	A.append(map(int, raw_input().split()))

res = 0
for i in xrange(n):
	for j in xrange(n):
		res += A[i][j]*A[j][i]
res %= 2

ans = []
k = int(raw_input())
for _ in xrange(k):
	op = map(int, raw_input().split())
	if op[0] == 3:
		ans.append(res)
	else:
		res = 1-res
print ''.join(map(str, ans))
