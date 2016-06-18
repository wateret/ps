#include <stdio.h>

char ans[1010][1010];
int pos[32];

// 0, 4, 7, 10, 13 ...
void edge(int a, int b) {
  ans[a][b] = ans[b][a] = 'Y';
}

int main()
{
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("2\nNY\nYN\n");
    return 0;
  }

  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++)
      ans[i][j] = 'N';

  int next = 2, maxm = -1;
  int linep, diap;
  for (int m = 30; m >= 0; m--) {
    if ((1<<m) & n) {
      if (maxm == -1) {
        maxm = m;
        // build diamonds
        edge(0, next);
        edge(0, next+1);
        next += 2;
        for (int i = 0; i < m-1; i++) {
          edge(next, next-2);
          edge(next, next-1);
          edge(next, next+1);
          edge(next, next+2);
          next += 3;
        }
        edge(1, next-1);
        edge(1, next-2);
        diap = next-3; diap = diap  == 1 ? 0 : diap;

        // build line
        next++;
        for (int i = 0; i < 150; i++) {
          edge(next, next-1);
          next++;
        }
        edge(next-1, 1);
        linep = next-1;
      } else {
        int t = maxm-m-1;
        int d = diap-t*3; d = d == 1 ? 0 : d;
        int l = linep-t*2;
        edge(d, l);
      }
    }
  }

  printf("%d\n", next);
  for (int i = 0; i < next; i++) {
    ans[i][next] = 0;
    printf("%s\n", ans[i]);
  }

  return 0;
}
