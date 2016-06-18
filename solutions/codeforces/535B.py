n = list(raw_input())

ans = 0
for v in n:
	ans <<= 1
	if v == '7':
		ans += 1
print ans+(2**len(n)-1)
		
