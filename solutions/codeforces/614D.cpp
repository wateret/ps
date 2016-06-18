#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> llll;

ll N, A, CF, CM, M;
llll E[100010];
ll AE[100010];
ll PS[100010];

int main() {
  scanf("%lld%lld%lld%lld%lld", &N, &A, &CF, &CM, &M);
  E[0] = make_pair(A, 0);
  for (int i = 1; i <= N; i++) {
    ll v;
    scanf("%lld", &v);
    E[i] = make_pair(v, i);
    AE[i] = v;
  }
  sort(E+1, E+1+N);
  reverse(E+1, E+1+N);
  for (int i = N; i >= 1; i--)
    PS[i] = PS[i+1]+E[i].first;

  ll mxv = 0, mxi = 0, mxk = 0;
  if (N*A-PS[1] <= M) {
    mxi = N;
    mxk = A;
    mxv = N*CF+A*CM;
  } else {
    int j = 0;
    for (int i = 0; i <= N; i++) {
      M -= A-E[i].first;
      if (M < 0) break;
      j = max(j, i+1);
      for (; j <= N; j++) {
        ll ejv = E[j].first;
        ll m = M-(ejv*(N-j+1)-PS[j]);
        if (m < 0) continue;
        ll k = ejv+m/(N-j+1);
        ll v = i*CF+k*CM;
        if (v > mxv) {
          mxi = i;
          mxk = k;
          mxv = v;
        }
        break;
      }
    }
  }
  printf("%lld\n", mxv);
  for (int i = 1; i <= N; i++)
    AE[i] = max(AE[i], mxk);
  for (int i = 1; i <= mxi; i++)
    AE[E[i].second] = A;
  for (int i = 1; i <= N; i++)
    printf("%lld%c", AE[i], i == N ? '\n' : ' ');

  return 0;
}
