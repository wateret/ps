#include <stdio.h>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define PI 3.14159265358979323846

int N;
ll A[100010];
set<pll> L;

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int r, h;
    scanf("%d%d", &r, &h);
    A[i] = 1ll*r*r*h;
  }

  ll ans = 0;
  L.insert(make_pair(0, 0));
  for (int i = 0; i < N; i++) {
    set<pll>::iterator beg = L.lower_bound(make_pair(A[i], 0));
    beg--;
    ll nsum = beg->second+A[i];
    pll nitem = make_pair(A[i], nsum);
    beg++;
    set<pll>::iterator end = beg;
    while (end != L.end() && end->second <= nsum)
      end++;
    L.erase(beg, end);
    L.insert(nitem);

    ans = max(ans, nsum);
  }
  printf("%.15f\n", PI*ans);

  return 0;
}