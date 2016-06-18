import math
n, ox, oy = map(int, raw_input().split())
inp = []
for _ in xrange(n):
    inp.append(map(int, raw_input().split()))

def distP(e):
    return (e[0]-ox)**2 + (e[1]-oy)**2

def distL(e):
    l = float((e[1][1]-e[0][1])**2+(e[1][0]-e[0][0])**2)
    r = float(((ox-e[0][0])*(e[1][0]-e[0][0])+(oy-e[0][1])*(e[1][1]-e[0][1]))/l)
    if 0 <= r and r <= 1:
        return float(((e[1][1]-e[0][1])*ox-(e[1][0]-e[0][0])*oy+e[1][0]*e[0][1]-e[1][1]*e[0][0])**2)/l
    else:
        return min(distP([e[0][0], e[0][1]]), distP([e[1][0], e[1][1]]))

far = max(map(distP, inp))
inp2 = zip(*(inp[i:] for i in range(2))) + [[inp[-1], inp[0]]]
near = min(map(distL, inp2))
print '%.20f' % ((far-near)*math.pi)