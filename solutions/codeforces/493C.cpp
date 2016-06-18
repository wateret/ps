#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

int N, M, A[200010], B[200010];

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);
  scanf("%d", &M);
  for (int i = 0; i < M; i++)
    scanf("%d", &B[i]);
  sort(A, A+N, greater<int>());
  sort(B, B+M, greater<int>());

  int a = 0, b = 0;
  int i = 0, j = 0;
  int bv = -1;
  while (i < N || j < M) {
    if (A[i] > B[j]) {
      if (A[i] != bv && a-b <= i-j)
        a = i, b = j;
      i++;
    } else {
      if (B[j] != bv && a-b <= i-j)
        a = i, b = j;
      j++;
    }
  }
  printf("%d:%d\n", 2*N+a, 2*M+b);
  return 0;
}
