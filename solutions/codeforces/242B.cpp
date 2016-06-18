#include <stdio.h>

int N, A[100010][2];

int solve() {
  int c[2] = { A[1][0], A[1][1] };
  int idx = 1;
  for (int i = 2; i <= N; i++) {
    if (A[i][0] < c[0] || (A[i][0] == c[0] && A[i][1] > c[1])) {
      c[0] = A[i][0];
      c[1] = A[i][1];
      idx = i;
    }
  }
  for (int i = 1; i <= N; i++) {
    if (i == idx) continue;
    if (A[i][1] > c[1]) return -1;
  }
  return idx;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d%d", &A[i][0], &A[i][1]);
  printf("%d\n", solve());
  return 0;
}