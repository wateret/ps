#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
typedef long long ll;

int N;
int C[100010];
int S[100010];
int V[100010];

void bfs(int s, int i)
{
  queue<int> q;
  q.push(s);
  int d = 0;
  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      int v = q.front();
      q.pop();
      if (v > 100000 || V[v] == i)
        continue;
      V[v] = i;
      S[v] += d;
      C[v]++;
      q.push(v/2);
      q.push(v*2);
    }
    d++;
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    bfs(x, i+1);
  }

  int ans = 987654321;
  for (int i = 1; i <= 100000; i++) {
    if (C[i] == N)
      ans = min(ans, S[i]);
  }
  printf("%d\n", ans);

  return 0;
}
