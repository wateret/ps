#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int sum[2][200010];
int pos[2][200010];
int posc[2], next[2];
vector<pair<int, int> > ans;

int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int v;
    scanf("%d", &v);
    v--;
    sum[0][i] = sum[0][i-1]+(v==0);
    sum[1][i] = sum[1][i-1]+(v==1);
    pos[v][++posc[v]] = i;
  }
  for (int t = 1; t <= N; t++) {
    int s0 = 0, s1 = 0;
    next[0] = next[1] = t;
    while (1) {
      int p0 = pos[0][next[0]];
      int p1 = pos[1][next[1]];
      if (p0 == 0 && p1 == 0)
        break;
      p0 = p0 == 0 ? 123456789 : p0;
      p1 = p1 == 0 ? 123456789 : p1;
      if (p0 < p1) {
        s0++;
        next[1] = sum[1][p0];
        if (p0 == N && s1 < s0) {
          ans.push_back(make_pair(s0, t));
          break;
        }
      } else {
        s1++;
        next[0] = sum[0][p1];
        if (p1 == N && s0 < s1) {
          ans.push_back(make_pair(s1, t));
          break;
        }
      }
      next[0] += t;
      next[1] += t;
    }
  }

  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }

  return 0;
}
