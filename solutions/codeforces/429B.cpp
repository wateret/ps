#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, M;
ll A[1010][1010];
ll dp[4][1010][1010];

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      scanf("%lld", &A[i][j]);

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      int r = N+1-i;
      int c = M+1-j;
      dp[0][i][j] = A[i][j] + max(dp[0][i-1][j], dp[0][i][j-1]); // LT
      dp[1][r][c] = A[r][c] + max(dp[1][r+1][c], dp[1][r][c+1]); // RB
      dp[2][r][j] = A[r][j] + max(dp[2][r+1][j], dp[2][r][j-1]); // LB
      dp[3][i][c] = A[i][c] + max(dp[3][i][c+1], dp[3][i-1][c]); // RT
    }

  ll ans = 0;
  for (int i = 2; i <= N-1; i++) {
    for (int j = 2; j <= M-1; j++) {
      ans = max(ans, dp[0][i][j-1]+dp[1][i][j+1]+dp[2][i+1][j]+dp[3][i-1][j]);
      ans = max(ans, dp[0][i-1][j]+dp[1][i+1][j]+dp[2][i][j-1]+dp[3][i][j+1]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
