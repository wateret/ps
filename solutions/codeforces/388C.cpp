#include <stdio.h>

int N;
int A[110][110];
int I[2][110];
int ans[2];

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &I[1][i]);
    for (int j = 0; j < I[1][i]; j++)
      scanf("%d", &A[i][j]);
    I[1][i]--;
  }

  int done = 0, t = 0;
  while (true) {
    int mxi[2] = {-1, -1}, mxv[2] = {0, 0};
    for (int i = 0; i < N; i++) {
      int range = I[1][i]-I[0][i];
      if (range < 0) continue;
      if (range%2 == 0) { // odd
        if (mxv[1] < A[i][(I[1][i]+I[0][i])/2]) {
          mxv[1] = A[i][(I[1][i]+I[0][i])/2];
          mxi[1] = i;
        }
      } else { // even
        if (mxv[0] < A[i][I[t][i]]) {
          mxv[0] = A[i][I[t][i]];
          mxi[0] = i;
        }
      }
    }
    if (mxi[1] == -1) // if no odd line
      mxi[1] = mxi[0];
    if (mxi[1] != -1) {
      ans[t] += A[mxi[1]][I[t][mxi[1]]];
      I[t][mxi[1]] += t == 0 ? 1 : -1;
      t = 1-t;
    } else {
      break;
    }
  }

  printf("%d %d\n", ans[0], ans[1]);

  return 0;
}
