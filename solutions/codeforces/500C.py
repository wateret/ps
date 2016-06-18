ints = lambda: map(int, raw_input().split())
n, m = ints()
W = [0] + ints()
I = ints()

rem = set(range(1, n+1))
sta = []
for v in I:
  if v in rem:
    rem.remove(v)
    sta.append(v)
sta += list(rem)
sta.reverse()
ans = 0
for v in I:
  idx = sta.index(v)
  ans += sum(map(lambda i: W[i], sta[idx+1:]))
  del sta[idx]
  sta.append(v)
print ans