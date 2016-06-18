#include <stdio.h>
#include <algorithm>
using namespace std;

int N, W;
int A[200010];

int main()
{
	scanf("%d%d", &N, &W);
	for (int i = 0; i < 2*N; i++)
		scanf("%d", &A[i]);
	sort(A, A+2*N);
	double ans = 0;
	if (A[0]*2 < A[N])
		ans = A[0]*3*N;
	else
		ans = A[N]/2.0*3*N;
	printf("%f\n", min(ans, (double)W));
	return 0;
}
