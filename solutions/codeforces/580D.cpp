#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int M, N, K;
int A[20];
int G[20][20];
ll dp[18][1<<18];
int val;
ll ans;

ll f(int l, int v) {
  ll& ret = dp[l][v];
  if (ret != -1) return ret;

  v &= ~(1 << l);
  if (v == 0)
    return A[l];

  ll res = 0;
  for (int i = 0; i < M; i++) {
    if ((1<<i) & v)
      res = max(res, f(i, v)+A[l]+G[i][l]);
  }
  return ret = res;
}

void dfs(int n, int v) {
  if (n < v) return;
  if (v == 0) {
    for (int i = 0; i < M; i++) {
      int mask = 1 << i;
      if (mask & val)
        ans = max(ans, f(i, val));
    }
    return;
  }
  val |= 1<<(n-1);
  dfs(n-1, v-1);
  val &= ~(1<<(n-1));
  dfs(n-1, v);
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d%d%d", &M, &N, &K);
  for (int i = 0; i < M; i++)
    scanf("%d", &A[i]);
  while (K--) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    G[x-1][y-1] = c;
  }

  dfs(M, N);
  printf("%lld\n", ans);

  return 0;
}
