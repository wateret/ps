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

char S[30];
int n;
vector<int> R;

int main()
{
	cin >> n;
	cin >> S;
	REP(i, n) {
		switch (S[i]) {
		case '0':
		case '1':
			break;
		case '2':
			R.push_back(2);
			break;
		case '3':
			R.push_back(3);
			break;
		case '4':
			R.push_back(3);
			R.push_back(2);
			R.push_back(2);
			break;
		case '5':
			R.push_back(5);
			break;
		case '6':
			R.push_back(5);
			R.push_back(3);
			break;
		case '7':
			R.push_back(7);
			break;
		case '8':
			R.push_back(7);
			R.push_back(2);
			R.push_back(2);
			R.push_back(2);
			break;
		case '9':
			R.push_back(7);
			R.push_back(2);
			R.push_back(3);
			R.push_back(3);
			break;
		default:
			break;
		}
	}
	sort(ALL(R), greater<int>());
	REP(i, R.size()) {
		cout << R[i];
	}
	cout << endl;
	return 0;
}
