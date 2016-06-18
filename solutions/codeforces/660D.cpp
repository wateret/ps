#include <stdio.h>
#include <map>
#include <tuple>
#include <utility>
using namespace std;

typedef long long ll;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int N;
int X[2010];
int Y[2010];

int main() {
  map< tuple<ll, int, int>, int > M;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d%d", &X[i], &Y[i]);
  }
  for (int i = 0; i < N; i++) {
    int x1 = X[i];
    int y1 = Y[i];
    for (int j = i+1; j < N; j++) {
      int x2 = X[j];
      int y2 = Y[j];
      int dx = x1-x2;
      int dy = y1-y2;
      ll dist = 1ll*dx*dx+1ll*dy*dy;
      int xx, yy;
      if (dx == 0) {
        xx = 0;
        yy = 1;
      } else if (dy == 0) {
        xx = 1;
        yy = 0;
      } else {
        int sign = dy >= 0 ? 1 : -1;
        int adx = abs(dx);
        int ady = abs(dy);
        int g = gcd(adx, ady);
        xx = sign*dx/g;
        yy = sign*dy/g;
      }
      auto key = make_tuple(dist, xx, yy);
      if (M.find(key) == M.end()) {
        M[key] = 1;
      } else {
        M[key]++;
      }
    }
  }
  int ans = 0;
  for (auto k : M) {
    int v = k.second;
    ans += v*(v-1)/2;
  }
  printf("%d\n", ans/2);
  return 0;
}
