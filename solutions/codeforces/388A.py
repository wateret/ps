raw_input()
A = sorted(map(int, raw_input().split()))
ans = 0
while len(A) > 0:
	c = 0
	for i in xrange(len(A)):
		if A[i] >= c:
			A[i] = -1
			c += 1
	A = filter(lambda x: x != -1, A)
	ans += 1
print ans
