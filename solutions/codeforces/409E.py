import itertools
x = float(raw_input())
t = itertools.product(*[range(1, 11), range(1, 11)])
_, a, h = min(map(lambda (a, h): (abs(((1.0*a*a/4*h*h)/(1.0*a*a/4+1.0*h*h))**0.5 - x), a, h), t))
print a, h
