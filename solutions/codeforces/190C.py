import sys
sys.setrecursionlimit(1000000)

n = int(raw_input())
A = raw_input().split()
l = len(A)

err = False
t = 0

def parseType():
    global t, err
    if t >= len(A):
        err = True
        return ''
    t += 1
    if A[t-1] == 'pair':
        return 'pair<' + parseType() + ',' + parseType() + '>'
    else:
        return 'int'

ans = parseType()
print ans if err == False and t == l else "Error occurred"
