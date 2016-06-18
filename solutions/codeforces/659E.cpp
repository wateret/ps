#include <stdio.h>
#include <vector>
using namespace std;

int N, M;
vector<int> G[100010];
bool V[100010];

int cyclic(int v, int p) {
  V[v] = true;
  for (int i = 0; i < G[v].size(); i++) {
    int e = G[v][i];
    if (!V[e]) {
      if (cyclic(e, v))
        return 1;
    } else if (e != p) {
      return 1;
    }
  }
  return 0;
}

int main() {
  scanf("%d%d", &N, &M);

  while (M--) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int ans = 0;
  for (int i = 1; i <= N; i++)
    if (!V[i])
      ans += 1-cyclic(i, 0);
  printf("%d\n", ans);
  
  return 0;
}
