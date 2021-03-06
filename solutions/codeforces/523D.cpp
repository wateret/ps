#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, K;
priority_queue<ll> Q;

int main() {
  scanf("%d%d", &N, &K);
  while (N--) {
    ll s, m;
    scanf("%lld%lld", &s, &m);
    if (Q.size() < K) {
      ll v = -s-m;
      Q.push(v);
      printf("%lld\n", -v);
    } else {
      ll mm = Q.top();
      Q.pop();
      ll v = min(mm, -s)-m;
      Q.push(v);
      printf("%lld\n", -v);
    }
  }
  return 0;
}