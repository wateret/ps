#include <stdio.h>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

struct DisjointSet {
  vector<int> parent, rank, count;

  DisjointSet(int n): parent(n), rank(n, 1), count(n, 1) {
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    if (rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if (rank[u] == rank[v]) rank[v]++;
    count[v] += count[u];
  }
};

struct rc {
  int r, c;
  rc(int r, int c) : r(r), c(c) {}
};

int N, M;
ll K;
int A[1010][1010];
int V[1010][1010];
int ANS[1010][1010];
int ansCnt;
map<int, vector<rc> > L;

int conv(int r, int c) { return r * M + c; }

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
void dfs(int r, int c, int n, DisjointSet& ds) {
  stack<rc> sta;
  sta.push(rc(r, c));
  while (!sta.empty()) {
    int r = sta.top().r;
    int c = sta.top().c;
    sta.pop();
    if (V[r][c]) continue;
    V[r][c] = 1;

    for (int i = 0; i < 4; i++) {
      int nr = r+dr[i];
      int nc = c+dc[i];
      if (nr < 0 || nr >= N || nc < 0 || nc >= M || A[nr][nc] < n)
        continue;
      ds.merge(conv(r, c), conv(nr, nc));
      sta.push(rc(nr, nc));
    }
  }
}

void dfsSolve(int r, int c, int n) {
  stack<rc> sta;
  sta.push(rc(r, c));
  while (!sta.empty()) {
    int r = sta.top().r;
    int c = sta.top().c;
    sta.pop();
    if (r < 0 || r >= N || c < 0 || c >= M || A[r][c] < n || ANS[r][c] || ansCnt == 0)
      continue;
    ANS[r][c] = n;
    ansCnt--;

    for (int i = 0; i < 4; i++) {
      int nr = r+dr[i];
      int nc = c+dc[i];
      sta.push(rc(nr, nc));
    }
  }
}


int main() {
  scanf("%d%d%lld", &N, &M, &K);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      int v;
      scanf("%d", &v);
      A[i][j] = v;
      if (L.find(v) == L.end())
        L.insert(make_pair(v, vector<rc>()));
      L[v].push_back(rc(i, j));
    }
  DisjointSet ds(M*N);
  map<int, vector<rc> >::iterator it = L.end();
  while (it != L.begin()) {
    it--;
    int n = it->first;
    vector<rc>& l = it->second;
    int mxc = 0;
    for (int i = 0; i < l.size(); i++) {
      int r = l[i].r;
      int c = l[i].c;
      if (!V[r][c]) {
        dfs(r, c, n, ds);
        int root = ds.find(conv(r, c));
        if (K % n == 0 && 1ll*ds.count[root]*n >= K) {
          printf("YES\n");
          ansCnt = K/n;
          dfsSolve(r, c, n);
          for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
              printf("%d%c", ANS[i][j], j == M-1 ? '\n' : ' ');
          return 0;
        }
      }
    }
  }
  printf("NO\n");
  return 0;
}
