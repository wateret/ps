#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int w, h;

bool cont(int w1, int h1, int w2, int h2)
{
	return w1 >= w2 && h1 >= h2;
}

bool test(int w2, int h2, int w3, int h3)
{
	if(cont(w, h, w2, h2)) {
		return cont(w-w2, h, w3, h3) || cont(w, h-h2, w3, h3);
	} else
		return false;
}

int main()
{
	int a2, a3, b2, b3;
	scanf("%d%d%d%d%d%d", &w,&h,&a2,&b2,&a3,&b3);
	printf(
		test(a2, b2, a3, b3) ||
		test(a2, b2, b3, a3) ||
		test(b2, a2, a3, b3) ||
		test(b2, a2, b3, a3) ? "YES\n" : "NO\n");
	return 0;
}
