n, k, p = map(int, raw_input().split())
q = k-p
A = map(int, raw_input().split())
O = filter(lambda x: x%2 == 1, A)
E = filter(lambda x: x%2 == 0, A)
lo = len(O)
le = len(E)

def impossible():
    print 'NO'
    exit()

if lo < q:
    impossible()
if (lo-q)%2 == 1:
    impossible()
otoe = (lo-q)//2

OO = []
EE = map(lambda x: [x], E)
i = 0
for _ in range(otoe):
    EE.append([O[i], O[i+1]])
    i += 2
for j in range(i, lo):
    OO.append([O[j]])

if le+otoe < p:
    impossible()

if p == 0:
    fe = []
    for z in EE:
        for zz in z:
            fe.append(zz)
    OO[0] = OO[0] + fe
    EEE = [[]]
else:
    oo = le+otoe-p+1
    fe = []
    for z in EE[:oo]:
        for zz in z:
            fe.append(zz)
    EEE = [fe]
    EEE += EE[oo:]

print 'YES'
for x in OO:
    print len(x), ' '.join(map(str, x))
if len(EEE[0]) > 0:
    for x in EEE:
        print len(x), ' '.join(map(str, x))
