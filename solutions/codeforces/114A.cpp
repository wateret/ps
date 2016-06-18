#include <iostream>
using namespace std;

int main()
{
    unsigned long long k, l, m;
    cin >> k >> l;
    m = 1;
    for (int i = 0; m < (1ull << 32); i++) {
        m *= k;
        if (m == l) {
            cout << "YES" << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
