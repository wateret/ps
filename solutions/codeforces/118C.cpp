n, k = map(int, raw_input().split())
s = raw_input()

DC = [0 for i in range(0, 10)]

for c in s:
	DC[int(c)] += 1

mdigit = -1
mcost = 1234567890
ms = ''
for i in range(0, 10):
	cost = 0
	rem = k
	ss = s
	for j in range(1, 11):
		diff = j/2
		d1 = (i-diff+10)%10
		d2 = (i+diff+10)%10
		if j%2 == 0:
			d = min(d1, d2)
		else:
			d = max(d1, d2)
		pp = min(rem, DC[d])
		cost += pp*diff
		rem -= pp
		if d < i:
			ss = ss[::-1].replace(str(d), str(i), pp)[::-1]
		else:
			ss = ss.replace(str(d), str(i), pp)
	if mcost > cost:
		mcost = cost
		mdigit = i
		ms = ss

print mcost
print ms
