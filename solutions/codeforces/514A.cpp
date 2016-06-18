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
	ll N, res = 0, p = 1;
	cin >> N;
	while (N) {
		ll d = N % 10;
		if (d == 9 && N/10 == 0) {
		}
		else if (d >= 5) {
			d = 9 - d;
		}
		res += p*d;
		p *= 10;
		N /= 10;
	}
	cout << res << endl;
	return 0;
}
