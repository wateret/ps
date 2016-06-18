#include <stdio.h>
#include <string.h>

char S[100100];
int M[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int C[3][13][32];

bool valid(int i) {
  for (int j = i; j < i+10; j++) {
    if (j-i == 2 || j-i == 5) {
      if (S[j] != '-') return false;
    } else {
      if (S[j] > '9' || S[j] < '0') return false;
    }
  }
  return true;
}

int toInt2(int i) {
  return (S[i]-'0')*10+(S[i+1]-'0');
}

int toInt4(int i) {
  return (S[i]-'0')*1000+(S[i+1]-'0')*100+(S[i+2]-'0')*10+(S[i+3]-'0');
}

int main() {
  scanf("%s", S);
  int L = strlen(S);
  for (int i = 0; i < L; i++) {
    if (!valid(i)) continue;
    int d = toInt2(i);
    int m = toInt2(i+3);
    int y = toInt4(i+6);
    if (y > 2015 || y < 2013) continue;
    if (m > 12 || m < 1) continue;
    if (d > M[m] || d < 1) continue;
    C[y-2013][m][d]++;
  }
  int mxv = 0;
  int ad, am, ay;
  for (int i = 0; i < 3; i++)
  for (int j = 1; j < 13; j++)
  for (int k = 1; k < 32; k++)
    if (mxv < C[i][j][k]) {
      ay = i;
      am = j;
      ad = k;
      mxv = C[i][j][k];
    }

  printf("%02d-%02d-%d\n", ad, am, ay+2013);
  return 0;
}
