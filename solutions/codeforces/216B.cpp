#include <stdio.h>

int N, M;
int G[110][110];
int V[110];
int ans, ans2;
bool cir;

int dfs(int c, int s) {
  if (V[c])
    return 0;
  V[c] = 1;
  int ret = 1;
  for (int i = 1; i <= N; i++) {
    if (G[c][i]) {
      if (i == s)
        cir = true;
      G[c][i] = G[i][c] = 0;
      ret += dfs(i, s);
    }
  }
  return ret;
}

int main() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a][b] = G[b][a] = 1;
  }
  for (int i = 1; i <= N; i++) {
    if (V[i])
      continue;
    cir = false;
    int ret = dfs(i, i);
    if (cir) {
      ans += ret%2;
    } else {
      ans2 = (ans2+ret)%2;
    }
  }
  printf("%d\n", ans+ans2);
  return 0;
}
