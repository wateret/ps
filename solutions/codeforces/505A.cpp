#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

string trytry(string s, int d) {
        int len = s.size();
        int ins = -1;
        for (int i = 0; i < len; i++) {
                if (s[i] != s[len-1-i]) {
                        if (ins != -1) {
                                return "NA";
                        } else {
                                ins = i;
                                if (d == 0)
                                        s.insert(len-i, 1, s[i]);
                                else
                                        s.insert(i, 1, s[len-1-i]);
                                len++;
                        }
                }
        }

        if (ins == -1) {
                if (len % 2 == 0) {
                        s.insert(len/2, 1, 'x');
                } else {
                        s.insert(len/2, 1, s[len/2]);
                }
        }
        return s;
}

int main()
{
        string s;
        cin >> s;
        string ret;
        ret = trytry(s, 0);
        if (ret != "NA") {
                cout << ret << endl;
        } else {
                cout << trytry(s, 1) << endl;
        }
        return 0;
}

