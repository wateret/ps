N = raw_input()
A = map(int, raw_input().split())

S = set()
R = []
for i in xrange(len(A)):
    if A[i] in S:
        R.append(i+1)
        S = set()
    else:
        S.add(A[i])

if len(R) == 0:
    print -1
else:
    print len(R)
    R[-1] = N
    for i in xrange(len(R)):
        if i == 0:
            print 1, R[i]
        else:
            print R[i-1]+1, R[i]