n = int(raw_input())
D = []
for _ in xrange(n):
        (x, y) = map(int, raw_input().split())
        D.append((x, y));

ans = 0
for c in D:
        n1 = len(filter(lambda i: c[0] == i[0] and c[1] > i[1], D))
        n2 = len(filter(lambda i: c[0] == i[0] and c[1] < i[1], D))
        n3 = len(filter(lambda i: c[0] > i[0] and c[1] == i[1], D))
        n4 = len(filter(lambda i: c[0] < i[0] and c[1] == i[1], D))
        if n1*n2*n3*n4 > 0:
                ans += 1
print ans