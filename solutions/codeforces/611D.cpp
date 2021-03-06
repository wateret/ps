#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int N;
char S[5010];
int dp[5010][5010];
int ni[5010][5010];

int x(int a, int b) {
  if (a >= N || b >= N) return 0;

  int &ret = ni[a][b];
  if (ret != -1) return ret;

  ret = 0;
  if (S[a] == S[b])
    ret = x(a+1, b+1)+1;
  return ret;
}

int f(int i, int l) {
  if (S[i] == '0') return 0;
  if (i+l > N) return 0;
  if (i+l == N) return 1;

  int& ret = dp[i][l];
  if (ret != -1) return ret;

  ret = f(i, l+1);
  if (i+l+l <= N) {
    int o = x(i, i+l);
    ret += (o < l && S[i+o] < S[i+l+o]) ? f(i+l, l) : f(i+l, l+1);
    ret %= MOD;
  }
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  memset(ni, -1, sizeof ni);
  scanf("%d%s", &N, S);
  printf("%d\n", f(0, 1));
  return 0;
}
