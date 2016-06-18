#include <stdio.h>

int N, K;

int main()
{
  int pcnt = 0;
  scanf("%d%d", &N, &K);
  for (int i = 0; i < K; i++) {
    int l, v, pv = -1;
    scanf("%d", &l);
    while(l--) {
      int v;
      scanf("%d", &v);
      if (pv != -1 && pv+1 != v)
        pcnt++;
      pv = v;
    }
  }
  printf("%d\n", pcnt+pcnt+K-1);

  return 0;
}
