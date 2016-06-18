#include <stdio.h>

int n;
bool A[1000010];
int cand[1000010];
int candc;
int r;
int ans[1000010];
int ansc;

int main()
{
  scanf("%d", &n);
  int pc = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    A[a] = true;
  }

  for (int i = 1; i <= 500000; i++) {
    int ri = 1000001-i;
    if (A[i] && A[ri]) {
      r += 2;
    } else if (A[i] && !A[ri]) {
      ans[ansc++] = ri;
    } else if (!A[i] && A[ri]) {
      ans[ansc++] = i;
    } else {
      cand[candc++] = i;
      cand[candc++] = ri;
    }
  }

  for (int i = 0; i < r; i++)
    ans[ansc++] = cand[i];

  printf("%d\n", ansc);
  for (int i = 0; i < ansc; i++) {
    printf("%d", ans[i]);
    printf(i != ansc-1 ? " " : "\n");
  }

  return 0;
}
