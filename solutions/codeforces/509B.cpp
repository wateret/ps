#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

typedef long long ll;

int n, k;
int A[110];
int R[110][110];

int main()
{
        cin >> n >> k;
        int mn = 100000, mx = -1;
        for (int i = 0; i < n; i++) {
                cin >> A[i];
                mn = min(A[i], mn);
                mx = max(A[i], mx);
        }
        if (mx - mn > k) {
                cout << "NO" << endl;
                return 0;
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < A[i]; j++) {
                        R[i][j] = 1;
                }
        }

        for (int i = 0; i < n; i++) {
                int n = 2;
                for (int j = mn + 1; j < A[i]; j++) {
                        R[i][j] = n;
                        n++;
                }
        }

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < A[i]; j++) {
                        if(j != 0)
                                cout << " ";
                        cout << R[i][j];
                }
                cout << endl;
        }
        return 0;
}

