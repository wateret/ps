#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

ll N, A, B;
ll X[1000010];
ll dp[1000010][3];
set<ll> PF;

#define INF (1ll<<60)

void pf(ll n) {
  int x = 2;
  while (x <= 500000 && n != 1) {
    if (n%x == 0) {
      n /= x;
      PF.insert(x);
    } else {
      x++;
    }
  }
  if (n != 1)
    PF.insert(n);
}

int main() {
  scanf("%lld%lld%lld", &N, &A, &B);
  for (int i = 1; i <= N; i++)
    scanf("%lld", &X[i]);
  pf(X[1]-1);
  pf(X[1]);
  pf(X[1]+1);
  pf(X[N]-1);
  pf(X[N]);
  pf(X[N]+1);
  ll ans = INF;
  for (set<ll>::iterator it = PF.begin(); it != PF.end(); it++) {
    ll p = *it;
    for (int i = 1; i <= N; i++) {
      // case 0, 2
      if (X[i]%p == 0) {
        dp[i][0] = dp[i-1][0];
        dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
      } else if ((X[i]-1)%p == 0 || (X[i]+1)%p == 0) {
        dp[i][0] = dp[i-1][0]+B;
        dp[i][2] = min(dp[i-1][1], dp[i-1][2])+B;
      } else {
        dp[i][0] = INF;
        dp[i][2] = INF;
      }
      // case 1
      dp[i][1] = min(dp[i-1][0], dp[i-1][1])+A;
    }
    ans = min(ans, dp[N][0]);
    ans = min(ans, dp[N][1]);
    ans = min(ans, dp[N][2]);
  }
  printf("%lld\n", ans);
  return 0;
}