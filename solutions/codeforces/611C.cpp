#include <stdio.h>

char S[510][510];
int P[510][510];
int LP[510][510];
int TP[510][510];
int H, W, Q;

int main() {
  scanf("%d%d", &H, &W);
  for (int i = 1; i <= H; i++)
    scanf("%s", &S[i][1]);
  for (int i = 1; i <= H; i++)
    for (int j = 1; j <= W; j++) {
      int l = (S[i][j] == '.' && S[i][j-1] == '.' ? 1 : 0);
      int t = (S[i][j] == '.' && S[i-1][j] == '.' ? 1 : 0);
      LP[i][j] = LP[i-1][j]+l;
      TP[i][j] = TP[i][j-1]+t;
      P[i][j] = P[i-1][j]+P[i][j-1]-P[i-1][j-1]+l+t;
    }
  scanf("%d", &Q);
  while (Q--) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int ans = P[r2][c2]-P[r2][c1-1]-P[r1-1][c2]+P[r1-1][c1-1];
    ans -= LP[r2][c1]-LP[r1-1][c1];
    ans -= TP[r1][c2]-TP[r1][c1-1];
    printf("%d\n", ans);
  }
}