#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

vector<int> ans;
int n, k;

int main()
{
  scanf("%d%d", &n, &k);
  if (n/2 > k) {
    printf("-1\n");
    return 0;
  }
  if (n == 1) {
    if (k == 0)
      printf("1\n");
    else
      printf("-1\n");
    return 0;
  }
  int nn = n/2-1;
  ans.push_back(k-nn);
  ans.push_back((k-nn)*2);
  for (int i = 0; i < nn; i++) {
    ans.push_back(200000001+i*2);
    ans.push_back(200000001+i*2+1);
  }
  if (n&1)
    ans.push_back(1000000000);
  for (int i = 0; i < ans.size(); i++) {
    printf("%d", ans[i]);
    printf(i == ans.size()-1 ? "\n" : " ");
  }
  return 0;
}

