#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K;
int A[500010];
int D[1000010];
int cnt;

void incr(int i) {
  if (D[A[i]] == 0) cnt++;
  D[A[i]]++;
}

void decr(int i) {
  D[A[i]]--;
  if (D[A[i]] == 0) cnt--;
}

int main() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; i++)
    scanf("%d", &A[i]);

  int ai = 0, aj = -1;
  int i = 1, j = 0;
  while (1) {
    while (cnt <= K && j <= N) {
      incr(++j);
    }
    if (j > N) {
      j--;
      if (j-i > aj-ai) {
        aj = j;
        ai = i;
      }
      break;
    } else {
      decr(j--);
      if (j-i > aj-ai) {
        aj = j;
        ai = i;
      }
    }
    while (cnt == K) {
      decr(i++);
    }
  }
  printf("%d %d\n", ai, aj);
  return 0;
}