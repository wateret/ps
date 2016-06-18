#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, k;
int a[101];
int b[101];

int main()
{
        cin >> n >> k;
        for (int i = 0; i < n; i++)
                cin >> a[i];

        vector<int> r;
        int cnt = 0;
        while (cnt < n) {
                int mnv = 1000;
                int mni = -1;
                for (int i = 0; i < n; i++) {
                        if (mnv > a[i]) {
                                mnv = a[i];
                                mni = i;
                        }
                }
                k -= mnv;
                if (k < 0)
                        break;
                a[mni] = 1000;
                r.push_back(mni);
                cnt++;
        }
        cout << r.size() << endl;
        for (int i = 0; i < r.size(); i++) {
                if (i != 0)
                        cout << " ";
                cout << (r[i]+1);
        }
        if (r.size() > 0)
                cout << endl;

        return 0;
}

