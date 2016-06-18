#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

int main()
{
	int N;
	double x0, y0;
	set<double> S;
	cin >> N >> x0 >> y0;
	while (N--) {
		double x, y;
		cin >> x >> y;
		double dx = x-x0;
		double dy = y-y0;
		if (dx == 0 && dy < 0)
			dy = -dy;
		S.insert(dy/dx);
	}
	cout << S.size() << endl;
	return 0;
}
