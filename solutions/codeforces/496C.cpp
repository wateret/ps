#include <stdio.h>

int N, M;
char S[110][110];
bool C[110];

int main()
{
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%s", S[i]);

  int ans = 0;
  for (int k = 0; k < 100; k++) {
  for (int i = 0; i < N-1; i++) {
    for (int j = 0; j < M; j++) {
      if (C[j])
        continue;
      char c1 = S[i][j], c2 = S[i+1][j];
      if (c1 > c2) {
        C[j] = true;
        ans++;
      } else if (c1 < c2) {
        break;
      }
    }
  }
  }
  printf("%d\n", ans);
  return 0;
}
