import itertools
n, k = map(int, raw_input().split())
A = []
for _ in xrange(n+1):
    A.append(raw_input())
nq = A.count('?') 
nz = A.count('0') 
if k == 0:
    if A[0] == '?':
        print 'No' if (n+1-nq)%2 == 0 else 'Yes'
    elif A[0] == '0':
        print 'Yes'
    else:
        print 'No'
else:
    if nq >= 1:
        print 'No' if (n+1)%2 == 1 else 'Yes'
    else:
        A = map(float, A)
        l = len(list(itertools.takewhile(lambda x: x == 0.0, A)))
        A = list(reversed(A))[:n+1-l]
        if len(A) == 0:
            print 'Yes'
        elif len(A) == 1:
            print 'No'
        else:
            b = A[0]
            for a in A[1:-1]:
                b = a+k*b
            print 'No' if -k*b != A[-1] else 'Yes'
