n = int(raw_input())
s1 = list(raw_input())
s2 = list(raw_input())

def f(a, b):
        v = abs(int(a)-int(b))
        return min(v, 10-v)

r = map(f, s1, s2)
print sum(r)
