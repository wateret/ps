#include <stdio.h>
#include <vector>
using namespace std;

int N, M;
vector<int> G[100010];
int R[100010];
int V[100010];
int ans;

void dfs(int x, int c) {
  if (V[x]) return;
  V[x] = 1;
  if (c <= M) {
    c = R[x] ? c+1 : 0;
  }
  if (G[x].size() == 1 && x != 1) {
    if (c <= M) ans++;
    return;
  }
  for (int i = 0; i < G[x].size(); i++)
    dfs(G[x][i], c);
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    scanf("%d", &R[i]);
  for (int i = 0; i < N-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}
