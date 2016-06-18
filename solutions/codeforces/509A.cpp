#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

typedef long long ll;

int a[10][10];

int main()
{
        int n;
        cin >> n;
        for (int i = 0; i < 10; i++)
                a[i][0] = a[0][i] = 1;
        for (int i = 1; i < 10; i++) {
                for (int j = 1; j < 10; j++) {
                        a[i][j] = a[i-1][j] + a[i][j-1];
                }
        }
        cout << a[n-1][n-1] << endl;
        return 0;
}

