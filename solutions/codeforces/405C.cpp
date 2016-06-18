#include <stdio.h>

int A[1010][1010];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &A[i][j]);
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      res += A[i][j]*A[j][i];
  res %= 2;

  int k;
  scanf("%d", &k);
  while (k--) {
    int op, t;
    scanf("%d", &op);
    if (op == 3) {
      printf("%d", res);
    } else {
      res = 1-res;
      scanf("%d", &t);
    }
  }
  printf("\n");
  return 0;
}
