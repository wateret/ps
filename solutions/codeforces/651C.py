n = int(raw_input())
X = {}
Y = {}
P = {}

def count(dic, key):
    try:
        dic[key] += 1
    except KeyError:
        dic[key] = 1

def calcComb(dic):
    return sum(map(lambda x: x*(x-1)/2, dic.values()))

for _ in xrange(n):
    x, y = map(int, raw_input().split())
    count(P, (x, y))
    count(X, x)
    count(Y, y)

print calcComb(X) + calcComb(Y) - calcComb(P)