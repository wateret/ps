#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int P[310], V[310];
char G[310][310];

void dfs(int v, int n) {
  if (V[v])
    return;
  V[v] = n+1;
  for (int i = 0; i < N; i++)
    if (G[v][i] == '1')
      dfs(i, n);
}

void sort() {
  for (int i = 0; i < N; i++)
    for (int j = i+1; j < N; j++)
      if (V[i] == V[j] && P[i] > P[j])
        swap(P[i], P[j]);
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", &P[i]);
  for (int i = 0; i < N; i++)
    scanf("%s", G[i]);
  for (int i = 0; i < N; i++)
    dfs(i, i);
  sort();
  for (int i = 0; i < N; i++) {
    printf("%d", P[i]);
    printf(i == N-1 ? "\n" : " ");
  }
}
