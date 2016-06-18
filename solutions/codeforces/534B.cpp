#include <iostream>
#include <algorithm>
using namespace std;

int v1, v2, t, d;

int nextd(int i, int cv)
{
	for (int j = d; j >= -d; j--)
		if (abs((cv+j)-v2) <= (t-i-1)*d)
			return j;
	return -1000000;
}

int main()
{
	cin>>v1>>v2>>t>>d;

	int cv = v1, ans = v1;
	for (int i = 1; i < t; i++) {
		cv += nextd(i, cv);
		ans += cv;
	}
	cout << ans << endl;
	return 0;
}
