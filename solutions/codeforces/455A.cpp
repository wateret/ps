#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
ll A[100010];
ll dp[100010];

int main() {
  scanf("%d", &N);
  while (N--) {
    ll v;
    scanf("%lld", &v);
    A[v]++;
  }
  for (ll i = 100000; i >= 1; i--)
    dp[i] = max(dp[i+2]+A[i]*i, dp[i+3]+A[i+1]*(i+1));
  printf("%lld\n", dp[1]);
  return 0;
}
