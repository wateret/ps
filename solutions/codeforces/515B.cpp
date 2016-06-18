#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
typedef long long ll;

int n, m;
int B[110], G[110];

int gcd(int p, int q)
{
	if (q == 0)
		return p;
	return gcd(q, p%q);
}

int lcm(int p, int q) {
	return p * q / gcd(p, q);
}

bool check()
{
	REP(i, n) {
		if (B[i] == 0)
			return false;
	}
	REP(i, m) {
		if (G[i] == 0)
			return false;
	}
	return true;
}

int main()
{
	cin >> n >> m;
	int l = lcm(n, m);

	int v;
	cin >> v;
	REP(i, v) {
		int x;
		cin >> x;
		B[x] = 1;
	}
	cin >> v;
	REP(i, v) {
		int x;
		cin >> x;
		G[x] = 1;
	}

	REP(j, 2) {
	REP(i, l) {
		if (B[i%n] || G[i%m]) {
			B[i%n] = G[i%m] = 1;
		}
	}
	}

	cout << (check() ? "Yes" : "No") << endl;
	return 0;
}
