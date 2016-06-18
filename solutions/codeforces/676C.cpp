#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K;
char A[100010];

int solve() {
  int i = 0, j = 0, k = 0, ans = 0;
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
      if (j-i > ans)
        ans = j-i;
    }
  }
  return ans;
}

int main() {
  scanf("%d%d", &N, &K);
  scanf("%s", A);

  for (int i = 0; i < N; i++)
    A[i] = A[i] == 'a' ? 1 : 0;
  int a1 = solve();

  for (int i = 0; i < N; i++)
    A[i] = 1-A[i];
  int a2 = solve();

  printf("%d\n", max(a1, a2));

  return 0;
}