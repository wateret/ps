#include <stdio.h>

int n, m, k;
char S[510][510];
char V[510][510];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c) {
  if (r < 0 || c < 0 || r >= n || c >= m || S[r][c] == '#')
    return;
  if (V[r][c])
    return;
  V[r][c] = 1;
  dfs(r+1, c);
  dfs(r-1, c);
  dfs(r, c+1);
  dfs(r, c-1);
  if (k > 0) {
    S[r][c] = 'X';
    k--;
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%s", S[i]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (S[i][j] == '.')
        dfs(i, j);
  for (int i = 0; i < n; i++)
    printf("%s\n", S[i]);

  return 0;
}
