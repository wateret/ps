#include <stdio.h>

int T, K;
int M[100010];
int P[100010];

int main() {
  scanf("%d%d", &T, &K);
  M[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    M[i] = M[i-1]+(i-K < 0 ? 0 : M[i-K]);
    M[i] %= 1000000007;
  }

  M[0] = 0;
  for (int i = 1; i <= 100000; i++)
    P[i] = (P[i-1]+M[i])%1000000007;

  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int r = P[b]-P[a-1];
    if (r < 0) r += 1000000007;
    printf("%d\n", r);
  }
  return 0;
}
