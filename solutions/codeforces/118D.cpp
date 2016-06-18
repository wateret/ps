#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define M 100000000
int N1, N2, K1, K2;
int dpf[110][110];
int dph[110][110];

int F(int f, int h);
int H(int f, int h);

int F(int f, int h)
{
  if (f == 0) return h == 0 ? 1 : 0;

  int& ret = dpf[f][h];
  if (ret != -1) return ret;

  int sum = 0;
  for (int i = 1; i <= min(K1, f); i++)
    (sum += H(f-i, h)) %= M;
  return ret = sum;
}

int H(int f, int h) {
  if (h == 0) return f == 0 ? 1 : 0;

  int& ret = dph[f][h];
  if (ret != -1) return ret;

  int sum = 0;
  for (int i = 1; i <= min(K2, h); i++)
    (sum += F(f, h-i)) %= M;
  return ret = sum;
}

int main()
{
  memset(dpf, -1, sizeof dpf);
  memset(dph, -1, sizeof dph);
  scanf("%d%d%d%d", &N1, &N2, &K1, &K2);
  printf("%d\n", (F(N1, N2) + H(N1, N2)) % M);
  return 0;
}
