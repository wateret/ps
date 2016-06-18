#include <stdio.h>

int r, g, h, rem;
int dp[200010];

int main() {
  scanf("%d%d", &r, &g);
  for (h = 1; h*(h+1)/2 <= r+g; h++);
  h--;
  rem = (r+g) - h*(h+1)/2;
  for (int i = 0; i <= rem; i++)
    dp[i] = 1;
  for (int i = 1; i <= h; i++)
    for (int j = r-i; j >= 0; j--)
      dp[j+i] = (dp[j+i]+dp[j])%1000000007;
  printf("%d\n", dp[r]);

  return 0;
}
