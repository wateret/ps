n = int(raw_input())
ans = -1
for i in range(1, 100):
    v = i*i+4*n
    vv = v**.5
    if int(vv-1)**2 != v and int(vv)**2 != v and int(vv+1)**2 != v:
        continue
    v = int(vv-i)
    if v % 2 == 1:
        continue
    v = v//2
    if i == sum(map(int, list(str(v)))):
        ans = v if ans == -1 else ans
print ans
