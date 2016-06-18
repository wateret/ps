#include <stdio.h>
#include <string.h>

int N, M, B, MOD;
int A[510];
int dp[510][510][510];

int f(int n, int m, int b) {
  if (m < 0 || b < 0)
    return 0;
  if (n == 0) {
    if (m == 0)
      return b >= 0 ? 1 : 0;
    else
      return 0;
  }

  int& ret = dp[n][m][b];
  if (ret != -1) return ret;
  return ret = (f(n, m-1, b-A[n]) + f(n-1, m, b)) % MOD;
}

int main() {
  scanf("%d%d%d%d", &N, &M, &B, &MOD);
  for (int i = 1; i <= N; i++)
    scanf("%d", &A[i]);
  memset(dp, -1, sizeof dp);
  printf("%d\n", f(N, M, B));
  return 0;
}
