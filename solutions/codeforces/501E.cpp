#include <stdio.h>

typedef long long ll;

int N, A[100010];
int B[100010], C[100010];
int odds, negs, chks;

void incr(int v, int d) {
  bool bst = B[v] < 0 || B[v] % 2 == 1;
  bool bst2 = B[v] < 0;
  B[v] += d;
  bool ast = B[v] < 0 || B[v] % 2 == 1;
  bool ast2 = B[v] < 0;
  if (bst != ast) {
    if (ast)
      odds++;
    else
      odds--;
  }
  if (bst2 != ast2) {
    if (ast2)
      negs++;
    else
      negs--;
  }
}

void valid(int i, int d) {
  int r = N-1-i;
  int v = A[i] == A[r] ? 0 : 1;
  i = i < r ? i : r;
  if (C[i] != d) {
    if (d == 0)
      chks -= v;
    else
      chks += v;
    C[i] = d;
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);

  for (int i = 0; i < (N-1)/2; i++)
    valid(i, 1);

  ll ans = 0;
  int i = 0, j = -1;
  bool force = true;
  while (i < N) {
    while (force || (j < N && (odds > 1 || negs > 0 || chks > 0))) {
      force = false;
      j++;
      int r = N-1-j;
      if (j == r) {
        incr(A[j], 1);
      } else if (i <= r && r <= j) {
        incr(A[j], 2);
      } else {
        valid(j, 0);
        incr(A[j], 1);
        incr(A[r], -1);
      }
    }
    ans += N-j;

    int r = N-1-i;
    if (i == r) {
      incr(A[i], -1);
    } else if (i <= r && r <= j) {
      incr(A[i], -2);
    } else {
      valid(i, 1);
      incr(A[i], -1);
      incr(A[r], 1);
    }
    i++;
    if (j < i) {
      force = true;
    }
  }
  printf("%lld\n", ans);
  return 0;
}