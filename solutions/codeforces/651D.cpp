#include <stdio.h>
#include <algorithm>
using namespace std;

int N, A, B, T;
char S[500010];

int solve() {
  int i = -1, t = T;
  while (i < N) {
    i++;
    int sub = 1;
    if (i != 0) sub += A;
    if (S[i] == 'w') sub += B;
    if (t < sub) break;
    t -= sub;
  }
  if (i == 0) return 0;
  int j = -1;
  while (N-1-j >= i) {
    j++;
    int sub = 1+A;
    if (j == 0) sub += A*(i-1);
    if (S[N-1-j] == 'w') sub += B;
    if (t < sub) break;
    t -= sub;
  }

  int ret = i+j;
  while (i > 1) {
    i--;
    t += A+1;
    if (j != 0) t += A;
    if (S[i] == 'w') t += B;
    for (; N-1-j >= i; j++) {
      int sub = 1+A;
      if (j == 0) sub += A*(i-1);
      if (S[N-1-j] == 'w') sub += B;
      if (t < sub) break;
      t -= sub;
    }
    ret = max(ret, i+j);
  }

  return ret;
}

int main() {
  scanf("%d%d%d%d", &N, &A, &B, &T);
  scanf("%s", S);

  int a = solve();
  for (int i = 1; i <= N/2; i++)
    swap(S[i], S[N-i]);
  int b = solve();
  printf("%d\n", max(a, b));

  return 0;
}
