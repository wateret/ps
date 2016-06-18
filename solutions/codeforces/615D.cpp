#include <stdio.h>
#include <vector>
using namespace std;

int N;
int ap[200010];
vector<int> la, ln, cl, cr;

typedef long long ll;
#define MOD 1000000007

int mult(int a, int b, int m) {
  return ((ll)a*(ll)b)%m;
}

int pow(int a, int n, int m) {
  if (n == 1)
    return a;

  int r = pow(a, n/2, m);
  r = mult(r, r, m);
  if (n%2 == 1)
    r = mult(r, a, m);
  return r;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int v;
    scanf("%d", &v);
    ap[v]++;
  }
  int bn = 1;
  int clt = 1;
  for (int i = 2; i <= 200000; i++) {
    if (ap[i] > 0) {
      la.push_back(i);
      ln.push_back(ap[i]);
      clt = mult(clt, ap[i]+1, MOD-1);
      cl.push_back(clt);
    }
  }
  int crt = 1;
  cr = vector<int>(cl.size(), 0);
  for (int i = cr.size()-1; i >= 0; i--) {
    crt = mult(crt, ln[i]+1, MOD-1);
    cr[i] = crt;
  }
  int ans = 1;
  int l = la.size();
  for (int i = 0; i < l; i++) {
    int sl = (i-1 >= 0 ? cl[i-1] : 1);
    int sr = (i+1 < l ? cr[i+1] : 1);
    int cn = mult(sl, sr, MOD-1);
    cn = mult(cn, ((ll)ln[i]*(ln[i]+1)/2)%(MOD-1), MOD-1);
    int t = pow(la[i], cn, MOD);
    ans = mult(ans, t, MOD);
  }
  printf("%d\n", ans);
  return 0;
}