n = int(raw_input())
numbers = lambda: map(int, raw_input().split())
A = numbers()
B = numbers()
C = numbers()

R = []
for i in xrange(n):
  R.append(sum(A[:i]+B[i:])+C[i])
R.sort()
print R[0]+R[1]