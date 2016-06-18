from Queue import Queue
import sys

def enc(a, r, c):
    return (a << 20) | (r << 10) | c

def dec(v):
    return v >> 20, (v >> 10) & 1023, v & 1023

ROTATE = {
    ord('+') : ord('+'),
    ord('-') : ord('|'), ord('|') : ord('-'),
    ord('^') : ord('>'), ord('>') : ord('v'), ord('v') : ord('<'), ord('<') : ord('^'),
    ord('L') : ord('U'), ord('U') : ord('R'), ord('R') : ord('D'), ord('D') : ord('L'),
    ord('*') : ord('*')
}

N, M = map(int, raw_input().split())
A = [[], [], [], []]
V = set()
for _ in xrange(N):
    A[0].append(map(ord, list(raw_input())))
    for i in xrange(1, 4):
        row = []
        for j in xrange(M):
            row.append(ROTATE[A[i-1][-1][j]])
        A[i].append(row)
SR, SC = map(lambda x: int(x)-1, raw_input().split())
ER, EC = map(lambda x: int(x)-1, raw_input().split())

DRC = [(0, -1), (0, 1), (-1, 0), (1, 0)]
LF = map(ord, list("+-<URD"))
RT = map(ord, list("+->LUD"))
UP = map(ord, list("+|^LRD"))
DO = map(ord, list("+|vLUR"))

ans = 0
Q = Queue()
Q.put(enc(0, SR, SC))
while not Q.empty():
    sz = Q.qsize()
    for _ in xrange(sz):
        a, r, c = rec = dec(Q.get())
        if rec in V:
            continue
        V.add(rec)
        if r == ER and c == EC:
            print ans
            sys.exit(0)
        Q.put(enc((a+1)%4, r, c))
        for dr, dc in DRC:
            nr = r+dr
            nc = c+dc
            if nr < 0 or nr >= N or nc < 0 or nc >= M or (a, nr, nc) in V:
                continue
            v1 = A[a][r][c]
            v2 = A[a][nr][nc]
            if (dc == -1 and v1 in LF and v2 in RT) or \
               (dc ==  1 and v1 in RT and v2 in LF) or \
               (dr == -1 and v1 in UP and v2 in DO) or \
               (dr ==  1 and v1 in DO and v2 in UP):
                Q.put(enc(a, nr, nc))
    ans += 1
print -1
