#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char S[2010], U[2010];

int main()
{
        cin >> S >> U;
        char *lstr = S, *sstr = U;
        int llen = strlen(S), slen = strlen(U);
        int base = slen;        // length of U

        if (slen > llen) {
                swap(slen, llen);
                swap(sstr, lstr);
        }

        int maxv = 0;
        for (int i = -slen; i <= llen; i++) {
                int v = 0;
                for (int j = 0; j < slen; j++) {
                        if (i+j >= 0 &&
                                i+j < llen &&
                                lstr[i+j] == sstr[j])
                                v++;
                }
                maxv = max(maxv, v);
        }
        cout << base-maxv << endl;
        return 0;
}
