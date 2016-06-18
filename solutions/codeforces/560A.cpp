#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int ans = 1;
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1)
			ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}
