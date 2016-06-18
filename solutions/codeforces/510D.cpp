#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
#define INF (10000000000000ll)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

#define encode(n, w) (n*1000000000ll+w)

int N;
ll l[310], c[310];
map<ll, ll> dp;

ll gcd(ll p, ll q)
{
        if (q == 0)
                return p;
        return gcd(q, p%q);
}

ll solve(ll n, ll w)
{
        if (n < 0 && w == 1)
                return 0;
        if (n < 0)
                return INF;
        ll key = encode(n, w);
        if (dp.find(key) != dp.end())
                return dp[key];

        return dp[key] = min(solve(n-1, w == 0 ? l[n] : gcd(w, l[n])) + c[n],
                                                 solve(n-1, w));
}

int main()
{
        cin >> N;
        REP(i, N)
                cin >> l[i];
        REP(i, N)
                cin >> c[i];

        ll res = solve(N-1, 0);
        cout << (res >= INF ? -1 : res) << endl;

        return 0;
}
