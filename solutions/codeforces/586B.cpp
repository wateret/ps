#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int A[2][60];
int C[60];
int R[60];

int main() {
  int t = 0, b = 0;
  scanf("%d", &N);
  for (int j = 0; j < 2; j++)
    for (int i = 0; i < N-1; i++) {
      scanf("%d", &A[j][i]);
      if (j == 1) b += A[j][i];
    }
  for (int i = 0; i < N; i++)
    scanf("%d", &C[i]);

  for (int i = 0; i < N; i++) {
    R[i] = t + b + C[i];
    t += A[0][i];
    b -= A[1][i];
  }
  sort(R, R+N);
  printf("%d\n", R[0]+R[1]);

  return 0;
}