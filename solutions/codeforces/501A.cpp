#include <iostream>
#include <algorithm>
using namespace std;

int calc(int p, int t)
{
        return max(3*p/10, p-p/250*t);
}

int main()
{
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (calc(a, c) > calc(b, d))
                cout << "Misha";
        else if (calc(a, c) < calc(b, d))
                cout << "Vasya";
        else
                cout << "Tie";
        cout << endl;
        return 0;
}
