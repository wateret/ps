#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int a[7];

int sq(int x) { return x*x; }
int main()
{
	int tri = 0, mxi = -1;
	for (int i = 0; i < 6; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 6; i++) {
		int v = a[i]+a[(i+1)%6]+a[i+2];
		if (tri < v) {
			tri = v;
			mxi = (i+1%6);
		}
	}
	int ans = sq(tri);
	int o = 1-mxi%2;
	printf("%d\n", ans-sq(a[o])-sq(a[2+o])-sq(a[4+o]));
	return 0;
}
