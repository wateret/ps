x1, y1, r1 = map(float, raw_input().split())
x2, y2, r2 = map(float, raw_input().split())

if r1 < r2:
    (x1,y1,r1), (x2,y2,r2) = (x2,y2,r2), (x1,y1,r1)

d = ((x1-x2)**2+(y1-y2)**2)**0.5
if d+r2 < r1:
        ans = (r1-d-r2)/2
elif d > r1+r2:
        ans = (d-r1-r2)/2
else:
        ans =  0.0
print '%.15f' % ans
