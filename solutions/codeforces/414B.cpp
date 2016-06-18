#include <stdio.h>

int N, K;
int dp[2010][2010];

int main()
{
  scanf("%d%d", &N, &K);
  for (int i = 0; i <= N; i++)
    dp[0][i] = 1;
  for (int i = 1; i <= K; i++) {
    for (int j = N; j >= 1; j--) {
      for (int x = j; x <= N; x += j) {
        dp[i][j] += dp[i-1][x];
        dp[i][j] %= 1000000007;
      }
    }
  }
  printf("%d\n", dp[K][1]);

  return 0;
}
