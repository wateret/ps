#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

#define MAXN (1<<16)
int n;
int d[MAXN], s[MAXN];

int main()
{
        int m = 0;
        queue<int> Q;
        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> d[i] >> s[i];
                m += d[i];
                if (d[i] == 1)
                        Q.push(i);
        }
        m /= 2;

        cout << m << endl;
        while (!Q.empty()) {
                int c = Q.front();
                Q.pop();
                if (d[c] < 1)
                        continue;
                int t = s[c];
                cout << c << " " << t << endl;
                d[c]--;
                d[t]--;
                if (d[t] == 1)
                        Q.push(t);
                s[c] = 0;
                s[t] ^= c;
        }

        return 0;
}
