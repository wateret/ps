#include <stdio.h>
#include <vector>
using namespace std;

int N;
vector<int> ans;
vector<int> G[100010];
bool R[100010], V[100010];

int dfs(int v, int f) {
  if (V[v]) return 0;
  V[v] = true;

  int ret = f;
  int ret2 = 0;
  for (int i = 0; i < G[v].size(); i++) {
    int n = G[v][i];
    int nf;
    if (n >= 0) {
      nf = 0;
    } else {
      nf = 1;
      n = -n;
    }
    if (!V[n])
      ret2 += dfs(n, nf);
  }
  if (!R[v] && ret == 1 && ret2 == 0)
    ans.push_back(v);
  R[v] = true;
  return ret+ret2;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N-1; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    G[a].push_back(w == 1 ? b : -b);
    G[b].push_back(w == 1 ? a : -a);
  }
  dfs(1, 0);
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d", ans[i]);
    printf(i == ans.size()-1 ? "\n" : " ");
  }

  return 0;
}
