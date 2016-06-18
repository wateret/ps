#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M;
int A[200010];
int QT[200010];
int QR[200010];
int C[200010];
int R[200010];

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; i++)
    scanf("%d", &A[i]);
  for (int i = 0; i < M ; i++)
    scanf("%d%d", &QT[i], &QR[i]);

  C[M] = M;
  for (int i = M-1; i >= 0 ; i--) {
    int ci = C[i+1];
    C[i] = QR[ci] < QR[i] ? i : ci;
  }

  int i = C[0];
  int l = 0, r = QR[i]-1, ri = r;
  sort(A, A+QR[i]);
  for (int j = QR[i]; j < N; j++)
    R[j] = A[j];
  while (l <= r) {
    int ni = C[i+1];
    int diff = QR[i]-QR[ni];
    while (diff--)
      R[ri--] = QT[i] == 1 ? A[r--] : A[l++];
    i = ni;
  }
  for (int j = 0; j < N; j++)
    printf("%d%c", R[j], j == N-1 ? '\n' : ' ');

  return 0;
}
