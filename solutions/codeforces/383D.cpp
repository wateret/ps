#include <stdio.h>

#define O 10005
#define MOD 1000000007

int N;
int A[1010];
int dp[1010][20010];

int main()
{
  int ans = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    dp[i][O-A[i]] = dp[i][O+A[i]] = 1;
  }
  for (int i = 1; i < N; i++) {
    for (int j = -10000; j <= 10000; j++) {
      int a = j-A[i], b = j+A[i];
      dp[i][O+j] += (a >= -10000 ? dp[i-1][O+a] : 0) +
                    (b <= 10000 ? dp[i-1][O+b] : 0);
      dp[i][O+j] %= MOD;
    }
    ans += dp[i][O];
    ans %= MOD;
  }
  printf("%d\n", ans);

  return 0;
}
