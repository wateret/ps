n, k = map(int, raw_input().split())

def test(v):
        ret = 0
        m = 1
        while True:
                x = v // m
                ret += x
                if x == 0:
                        return ret >= n
                if ret >= n:
                        return True
                m *= k

def solve():
        lo = 0
        hi = n*2
        while lo+1 < hi:
                mid = (lo+hi)//2
                r1 = test(mid)
                r2 = test(mid+1)
                if r1 != r2:
                        return mid+1
                elif r1:
                        hi = mid
                else:
                        lo = mid
        return hi

print solve()