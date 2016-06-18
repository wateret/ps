#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

int N;
int dp[3][100010];
int X[100010], H[100010];

int solve(int l, int c)
{
	if (c > N)
		return 0;
	int& ret = dp[l][c];
	if (ret != -1)
		return ret;

	// leave
	ret = solve(1, c+1);

	// cut left
	int lx = X[c-1];
	if (l == 2)
		lx += H[c-1];
	if (lx < X[c]-H[c])
		ret = max(ret, solve(0, c+1)+1);

	// cut right
	if (X[c+1] > X[c]+H[c])
		ret = max(ret, solve(2, c+1)+1);

	return ret;
}

int main()
{
	memset(dp, -1, sizeof dp);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &X[i], &H[i]);
	X[0] = -1000000010;
	X[N+1] = 2000000010;

	printf("%d\n", solve(0, 1));
	return 0;
}
