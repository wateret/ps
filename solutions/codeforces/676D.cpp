#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
int SR, SC, ER, EC;
char A[4][1010][1010];
bool V[4][1010][1010];
char R[256];
char left[] = "+-<URD";
char right[] = "+->LUD";
char up[] = "+|^LRD";
char down[] = "+|vLUR";

int enc(int a, int r, int c) { return (a << 20) | (r << 10) | c; }
int dec_a(int v) { return v >> 20; }
int dec_r(int v) { return (v >> 10) & 1023; }
int dec_c(int v) { return v & 1023; }

const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};
int main() {
  R['+'] = '+';
  R['-'] = '|'; R['|'] = '-';
  R['^'] = '>'; R['>'] = 'v'; R['v'] = '<'; R['<'] = '^';
  R['L'] = 'U'; R['U'] = 'R'; R['R'] = 'D'; R['D'] = 'L';
  R['*'] = '*';
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%s", A[0][i]);
  scanf("%d%d", &SR, &SC);
  scanf("%d%d", &ER, &EC);
  SR--; SC--; ER--; EC--;
  for (int i = 1; i < 4; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < M; k++)
        A[i][j][k] = R[A[i-1][j][k]];

  queue<int> Q;
  int ans = 0;
  Q.push(enc(0, SR, SC));
  while (!Q.empty()) {
    int sz = Q.size();
    while (sz--) {
      int v = Q.front();
      Q.pop();
      int a = dec_a(v);
      int r = dec_r(v);
      int c = dec_c(v);
      if (V[a][r][c]) continue;
      V[a][r][c] = true;
      if (r == ER && c == EC) {
        printf("%d\n", ans);
        return 0;
      }
      Q.push(enc((a+1)%4, r, c));
      for (int i = 0; i < 4; i++) {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M || V[a][nr][nc])
          continue;
        char v1 = A[a][r][c];
        char v2 = A[a][nr][nc];
        if ((i == 0 && strchr(left, v1) && strchr(right, v2)) ||
            (i == 1 && strchr(right, v1) && strchr(left, v2)) ||
            (i == 2 && strchr(up, v1) && strchr(down, v2)) ||
            (i == 3 && strchr(down, v1) && strchr(up, v2)))
          Q.push(enc(a, nr, nc));
      }
    }
    ans++;
  }

  printf("%d\n", -1);
  return 0;
}