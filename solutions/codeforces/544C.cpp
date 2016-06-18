#include <stdio.h>

int N, M, B, mod;
int A[510];
int dp[510][510];

int main()
{
	scanf("%d%d%d%d", &N, &M, &B, &mod);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	
	for (int i = 0; i <= B; i++)
		dp[0][i] = 1;
	for (int i = 1; i <= N; i++) {
		int a = A[i];
		for (int j = 1; j <= M; j++)
			for (int k = a; k <= B; k++)
				dp[j][k] = (dp[j][k]+dp[j-1][k-a])%mod;
	}

	printf("%d\n", dp[M][B]);

	return 0;
}
