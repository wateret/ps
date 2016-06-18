#include <stdio.h>

int N, mn[3], mx[3], di[3];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < 3; i++) {
		scanf("%d%d", &mn[i], &mx[i]);
		di[i] = mx[i]-mn[i];
	}
	N -= mn[0]+mn[1]+mn[2];
	for (int i = 0; i < 3; i++) {
		int r;
		if (N > di[i]) r = di[i]; else r = N;
		N -= r;
		printf("%d", mn[i]+r);
		printf(i != 2 ? " " : "\n");
	}

	return 0;
}
