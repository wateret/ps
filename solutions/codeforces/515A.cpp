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

int main()
{
	int a, b, s;
	cin >> a >> b >> s;
	int c = abs(a) + abs(b);
	cout << (c <= s && (s-c) % 2 == 0 ? "Yes" : "No") << endl;
	return 0;
}
