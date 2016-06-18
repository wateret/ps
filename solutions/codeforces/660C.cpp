#include <stdio.h>

int N, K;
int A[300010];

int main() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);

  int i = 0, j = 0, k = 0, ans = 0, ai, aj;
  while (j < N) {
    if (i > j)
      j = i;
    if (k == K && A[j] == 0) {
      if (A[i] == -1) {
        A[i] = 0;
        k--;
      }
      i++;
    } else {
      if (A[j] == 0) {
        A[j] = -1;
        k++;
      }
      j++;
      if (j-i > ans) {
        ans = j-i;
        ai = i;
        aj = j;
      }
    }
  }

  printf("%d\n", ans);
  for (int i = 0; i < N; i++) {
    if (A[i] == -1) A[i] = 0;
    if (ai <= i && i < aj) A[i] = 1;
    printf("%d%c", A[i], i == N-1 ? '\n' : ' ');
  }

  return 0;
}
