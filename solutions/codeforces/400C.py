h, w, x, y, z, p = map(int, raw_input().split())
oh, ow = h, w
x %= 4
y %= 2
z %= 4
for _ in xrange(p):
	h, w = oh, ow
	r, c = map(int, raw_input().split())
	for _ in xrange(x):
		r, c = c, h+1-r
		h, w = w, h
	c = w+1-c if y == 1 else c
	for _ in xrange(z):
		r, c = w+1-c, r
		h, w = w, h
	print r, c
