#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int N, P;
char S[100010];

int main() {
  scanf("%d%d%s", &N, &P, S);
  int rn = (N+1)/2;
  P--;
  if (P >= rn) P = N-1-P;
  int lo = P, hi = P;
  int ans = 0;
  for (int i = 0; i < rn; i++) {
    int d = abs(S[i]-S[N-1-i]);
    S[i] = min(26-d, d);
    ans += S[i];
    if (S[i] > 0) {
      hi = i;
      if (i < lo)
        lo = i;
    }
  }
  ans += (hi-lo) + min(abs(hi-P), abs(lo-P));
  printf("%d\n", ans);

  return 0;
}