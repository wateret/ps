#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int A[100010];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	sort(A, A+N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int ans = 1, sum = A[0];
	for (int i = 1; i < N; i++) {
		if (A[i] >= sum) {
			ans++;
			sum += A[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
