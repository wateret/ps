#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

typedef long long ll;

#define L(i, c) ((i)-(1ll<<(c-1)))
#define R(i, c) ((i)+(1ll<<(c-1)))

ll h, n;

ll solve(ll d, ll cn, int dir)
{
        ll ch = h+1-d;
        if (cn == n)
                return 0;

        if (dir == 0) {
                if (cn > n) {
                        return solve(d+1, L(cn, ch), 1-dir) + 1;
                } else {
                        return solve(d+1, R(cn, ch), dir) + (1ll << ch);
                }
        } else {
                if (cn < n) {
                        return solve(d+1, R(cn, ch), 1-dir) + 1;
                } else {
                        return solve(d+1, L(cn, ch), dir) + (1ll << ch);
                }
        }
}

int main()
{
        cin >> h >> n;
        n = 2 * n - 1;
        cout << solve(1, (1ll<<h), 0) << endl;

        return 0;
}

