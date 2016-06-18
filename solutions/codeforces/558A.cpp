#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
typedef long long ll;

int N;
pair<int, int> D[110];

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int x, a;
    scanf("%d%d", &x, &a);
    D[i] = make_pair(x, a);
  }
  D[N] = make_pair(0, 0);
  sort(D, D+N+1);
  int p;
  for (int i = 0; i <= N; i++) {
    p = i;
    if (D[i].first == 0)
      break;
  }

  int ans = 0;
  int v = min(N-p, p);
  for (int i = p-v; i <= p+v; i++)
    ans += D[i].second;
  if (p > N-p)
      ans += D[p-v-1].second;
  else if (p < N-p)
      ans += D[p+v+1].second;

  printf("%d\n", ans);
  return 0;
}
