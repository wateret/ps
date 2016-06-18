s = raw_input()
cnt = s.count('#')
sta = 0
ans = []
for c in s:
	if c == '(':
		sta += 1
	elif c == ')':
		sta -= 1
	else:
		if sta >= 1:
			ans += [1]
			sta -= 1
		else:
			print -1
			exit(0)
ans.pop()
ans += [sta+1]
if sta < 0:
	print -1
	exit(0)

i = 0
sta = 0
for c in s:
	if c == '(':
		sta += 1
	elif c == ')':
		sta -= 1
	else:
		sta -= ans[i]
		i += 1
	if sta < 0:
		print -1
		exit(0)
for v in ans:
	print v
