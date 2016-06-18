from math import log
x, y, z = map(float, raw_input().split())

def f(a, b, c):
    return log(b*c*log(a))
def g(a, b, c):
    return c*log(b)+log(log(a))

print sorted([
    [g(x, y, z),  -1, 'x^y^z'],
    [g(x, z, y),  -2, 'x^z^y'],
    [f(x, y, z),  -3, '(x^y)^z'],
    [f(x, z, y),  -4, '(x^z)^y'],
    [g(y, x, z),  -5, 'y^x^z'],
    [g(y, z, x),  -6, 'y^z^x'],
    [f(y, x, z),  -7, '(y^x)^z'],
    [f(y, z, x),  -8, '(y^z)^x'],
    [g(z, x, y),  -9, 'z^x^y'],
    [g(z, y, x), -10, 'z^y^x'],
    [f(z, x, y), -11, '(z^x)^y'],
    [f(z, y, x), -12, '(z^y)^x']
])[-1][2]
