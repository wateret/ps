#include <stdio.h>
#include <set>
#include <utility>
#include <iterator>
using namespace std;

#define VAL (itr->first)
#define IDX (-itr->second)

typedef pair<int, int> ii;

int N;
int T[100010][4];
set<ii> S;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int v;
    scanf("%d", &v);
    auto itr = S.insert(make_pair(v, -i)).first;
    if (i == 1) continue;
    itr++;
    if (itr != S.end() && T[IDX][1] == 0) {
      T[i][0] = VAL;
      T[IDX][1] = v;
    }
    itr--;
    if (itr != S.begin()) {
      itr--;
      if (T[IDX][2] == 0) {
        T[i][0] = VAL;
        T[IDX][2] = v;
      }
    }
  }

  for (int i = 2; i <= N; i++)
    printf("%d%c", T[i][0], i == N ? '\n' : ' ');

  return 0;
}
