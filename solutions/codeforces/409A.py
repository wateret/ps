s1 = raw_input()
s2 = raw_input()
def calc(a, b):
    a = [a[i:i+2] for i in range(0, len(a), 2)]
    b = [b[i:i+2] for i in range(0, len(b), 2)]
    v = map(lambda a, b: {'()[]': 1, '()8<': -1, '()()': 0, '8<[]': -1, '8<()': 1, '8<8<': 0, '[]8<': 1, '[]()': -1, '[][]': 0}[a+b], a, b)
    return sum(v)
v = calc(s1, s2)
if v < 0:
    print 'TEAM 1 WINS'
elif v > 0:
    print 'TEAM 2 WINS'
else:
    print 'TIE'