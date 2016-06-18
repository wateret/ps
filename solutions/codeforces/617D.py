getp = lambda: map(int, raw_input().split())
x1, y1 = getp()
x2, y2 = getp()
x3, y3 = getp()
xc = len(set([x1, x2, x3]))
yc = len(set([y1, y2, y3]))
mc = min(xc, yc)
if mc == 1 or mc == 3:
    print mc
else:
    if xc == yc:
        print 2
    else:
        if xc == 2:
            if x1 == x2:
                a, b, m = y1, y2, y3
            elif x2 == x3:
                a, b, m = y2, y3, y1
            else:
                a, b, m = y1, y3, y2
        else:
            if y1 == y2:
                a, b, m = x1, x2, x3
            elif y2 == y3:
                a, b, m = x2, x3, x1
            else:
                a, b, m = x1, x3, x2
        if a > b:
            a, b = b, a
        if a < m and m < b:
            print 3
        else:
            print 2
