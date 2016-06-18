#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

class IntervalTree
{
  ll* tree;
  ll* lazy;
  int n;

  void build_tree(const vector<ll>& v, int node, int a, int b)
  {
    if (a > b) return;
    if (a == b) {
      tree[node] = v[a];
      return;
    }

    build_tree(v, node * 2, a, (a + b) / 2);
    build_tree(v, node * 2 + 1, 1 + (a + b) / 2, b);
    tree[node] = tree[node * 2] | tree[node * 2 + 1];
  }

  void update_lazy(int node, int a, int b)
  {
    if (lazy[node] == -1)
      return;

    tree[node] = lazy[node];
    if (a != b)
    {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = -1;
  }

  void update_tree(int node, int a, int b, int i, int j, ll value)
  {
    if (lazy[node] != 0) update_lazy(node,a,b);

    if (a > b || a > j || b < i) return;

    if (a >= i && b <= j)
    {
      tree[node] = value;
      if (a != b)
      {
        lazy[node * 2] = value;
        lazy[node * 2 + 1] = value;
      }
      return;
    }

    update_tree(node * 2, a, (a + b) / 2, i, j, value);
    update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);

    tree[node] = tree[node * 2] | tree[node * 2 + 1];
  }

  ll query_tree(int node, int a, int b, int i, int j)
  {
    if (a > b || a > j || b < i) return 0;

    if (lazy[node] != 0) update_lazy(node,a,b);

    if (a >= i && b <= j) return tree[node];

    ll q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
    ll q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

    return q1 | q2;
  }

public:
  IntervalTree(const vector<ll>& v)
  {
    n = v.size();
    int s = 4*n;
    tree = new ll[s];
    lazy = new ll[s];

    memset(lazy, -1, s*sizeof(ll));
    build_tree(v, 1, 0, n - 1);
  }

  void update(int idx1, int idx2, ll newval)
  {
    update_tree(1, 0, n - 1, idx1, idx2, newval);
  }

  ll query(int idx1, int idx2)
  {
    return query_tree(1, 0, n - 1, idx1, idx2);
  }
};

int N, M;
int A[400010];
vector<int> T[400010]; // tree
vector<ll> SN; // serialized tree nodes
int BE[400010][2];

void dfs(int p, int c) {
  BE[c][0] = SN.size();
  SN.push_back(c);
  for (int i = 0, sz = T[c].size(); i < sz; i++)
    if (p != T[c][i])
      dfs(c, T[c][i]);
  BE[c][1] = SN.size()-1;
}

int cbits(ll n) {
  int ret = 0;
  while (n) {
    ret += n&1;
    n >>= 1;
  }
  return ret;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);
  for (int i = 0; i < N-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    T[a-1].push_back(b-1);
    T[b-1].push_back(a-1);
  }

  dfs(-1, 0);
  for (int i = 0; i < N; i++)
    SN[i] = 1ll << A[SN[i]];

  IntervalTree roq(SN);

  while (M--) {
    int t, v, c;
    scanf("%d%d", &t, &v);
    v--;
    if (t == 1) {
      scanf("%d", &c);
      roq.update(BE[v][0], BE[v][1], 1ll << c);
    } else {
      printf("%d\n", cbits(roq.query(BE[v][0], BE[v][1])));
    }
  }
  return 0;
}