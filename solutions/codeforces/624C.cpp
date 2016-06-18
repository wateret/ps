#include <stdio.h>
#include <vector>
using namespace std;

int G[510][510];
int N, M;
char A[510];
vector<int> CC[510];
int CCL;

void findB(int v) {
  for (int i = 1; i <= N; i++)
    if (v != i && !G[v][i]) return;
  for (int i = 1; i <= N; i++)
    G[v][i] = 0;
  A[v] = 'b';
}

void group(int v) {
  if (A[v]) return;
  CC[CCL].push_back(v);
  A[v] = CCL == 1 ? 'a' : 'c';
  for (int i = 1; i <= N; i++)
    if (G[v][i]) group(i);
}

bool complete() {
  for (int k = 1; k <= CCL; k++) {
    int sz = CC[k].size();
    for (int i = 0; i < sz; i++) {
      int a = CC[k][i];
      for (int j = 0; j < sz; j++) {
        int b = CC[k][j];
        if (a != b && !G[a][b]) return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a][b] = G[b][a] = 1;
  }
  for (int i = 1; i <= N; i++)
    findB(i);
  for (int i = 1; i <= N; i++)
    if (!A[i]) {
      CCL++;
      group(i);
    }
  if (CCL > 2 || !complete())
    printf("No\n");
  else
    printf("Yes\n%s\n", A+1);
  return 0;
}