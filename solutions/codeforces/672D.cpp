#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
ll K;
int A[500010];

int main() {
  scanf("%d%lld", &N, &K);
  ll sum = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    sum += A[i];
  }
  sort(A+1, A+N+1);
  A[N+1] = A[N]+1;

  int l = 0, r = N+1;
  int lo = A[1], hi = A[N];
  int saved = 0;
  while (K > 0 && l <= r) {
    // get
    int nr = r-1;
    while (nr >= 1 && A[nr] == A[nr-1]) nr--;
    ll width = N+1-nr;
    ll height = A[nr]-A[nr-1];
    ll area = 1ll*width*height;
    ll got = min(area, K);
    K -= got;
    hi = A[nr] - got/width;
    r = nr;
    // put
    saved += got;
    while (saved > 0 && l <= r) {
      int nl = l+1;
      while (nl <= N && A[nl] == A[nl+1]) nl++;
      width = nl;
      height = min(A[nl+1], hi)-lo;
      area = width*height;
      if (saved >= area) {
        lo = A[nl+1];
        saved -= area;
        l = nl;
      } else {
        lo = lo + saved/width;
        saved = saved%width;
        break;
      }
    }
  }
//  printf("%d %d\n", hi, lo);
  int ans = hi-lo;
  if (l > r)
    ans = sum%N == 0 ? 0 : 1;
  printf("%d\n", ans);
  return 0;
}
