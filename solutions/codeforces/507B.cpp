#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
#include <utility>
using namespace std;

long long r, x, y, xx, yy;

int main()
{
        cin >> r >> x >> y >> xx >> yy;

        double dx = x-xx;
        double dy = y-yy;
        double dist = sqrt(dx*dx + dy*dy);
        int res = ceil(dist / (2*r));

        cout << res << endl;

        return 0;
}

