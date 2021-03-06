#include <stdio.h>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int M, N;
char S[100010];
int dp[2010][2010];

int main() {
  scanf("%d%d%s", &M, &N, S);
  int K = M-N;
  int L = 0, ML = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    L += S[i] == '(' ? 1 : -1;
    ML = min(ML, L);
  }
  ML = -ML;
  dp[0][0] = 1;
  for (int i = 1; i <= 2000; i++) {
    for (int j = 0; j <= 2000; j++) {
      dp[i][j] = (j-1 >= 0    ? dp[i-1][j-1] : 0) +
                 (j+1 <= 2000 ? dp[i-1][j+1] : 0);
      dp[i][j] %= MOD;
    }
  }
  for (int i = 0; i <= K; i++) {
    for (int j = ML; j <= i; j++) {
      if (j+L > K-i)
        break;
      ans += (1LL*dp[i][j]*dp[K-i][j+L])%MOD;
      ans %= MOD;
    }
  }
  printf("%d\n", ans);
  return 0;
}
