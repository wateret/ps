#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
        map<string, string> M;
        vector<string> R;
        int n;
        cin >> n;
        while (n--) {
                string a, b;
                cin >> a >> b;
                if (M.find(a) == M.end())
                        R.push_back(a);
                M[a] = b;
                M[b] = "";
        }

        cout << R.size() << endl;
        for (int i = 0; i < R.size(); i++) {
                string cur = R[i];
                while (true) {
                        if (M[cur] == "")
                                break;
                        cur = M[cur];
                }
                cout << R[i] << " " << cur << endl;
        }
        return 0;
}
