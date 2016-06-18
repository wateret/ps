#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

struct FenwickTree
{
  vector<int> tree;

  FenwickTree(int n = 0) {
    tree.resize(n);
  }

  void update(int i, int delta) {
    for (; i < (int)tree.size(); i |= i + 1)
      tree[i] += delta;
  }

  int sum(int ind) {
    int sum = 0;
    while (ind>=0)
    {
      sum += tree[ind];
      ind &= ind + 1;
      ind--;
    }
    return sum;
  }

  int sumRange(int hi, int lo) {
    return sum(hi) - sum(lo);
  }

  int val(int i) {
    return sum(i) - sum(i-1);
  }
};

int N, Q;

int main()
{
  scanf("%d%d", &N, &Q);
  FenwickTree ft(100010);
  for (int i = 1; i <= N; i++)
    ft.update(i, 1);
  int L = 0, R = N;
  bool l = true;
  while (Q--) {
    int op, a, b;
    scanf("%d%d", &op, &a);
    if (op == 1) {
      int ra = R-L-a;
      if (l) {
        if (a <= ra) {
          L += a;
          for (int i = 0; i < a; i++)
            ft.update(L+i+1, ft.val(L-i));
        } else {
          R -= ra;
          for (int i = 0; i < ra; i++)
            ft.update(R-i, ft.val(R+i+1));
          l = false;
        }
      } else {
        if (a <= ra) {
          R -= a;
          for (int i = 0; i < a; i++)
            ft.update(R-i, ft.val(R+i+1));
        } else {
          L += ra;
          for (int i = 0; i < ra; i++)
            ft.update(L+i+1, ft.val(L-i));
          l = true;
        }
      }
    } else {
      scanf("%d", &b);
      int ans = l ? ft.sumRange(L+b, L+a) : ft.sumRange(R-a, R-b);
      printf("%d\n", ans);
    }
  }
  return 0;
}