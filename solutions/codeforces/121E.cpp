#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
typedef long long ll;

int N, M;
int A[100010];
int T[500010];
int L[10001];

int isLucky(int n) {
    while (n) {
        int d = n%10;
        if (d != 4 && d != 7)
            return 0;
        n /= 10;
    }
    return 1;
}

int sum(int pos) {
    ++pos;
    int ret = 0;
    while (pos > 0) {
        ret += T[pos];
        pos &= (pos-1);
    }
    return ret;
}

void add(int pos, int val) {
    if (pos < 0)
        return;
    ++pos;
    while (pos <= N) {
        T[pos] += val;
        pos += (pos & -pos);
    }
}

int main()
{
    const int ln[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777};
    REP(i, sizeof(ln)/sizeof(ln[0])) {
        L[ln[i]] = 1;
    }

    scanf("%d%d", &N, &M);
    REP(i, N) {
        cin >> A[i];
        if (L[A[i]])
            add(i, 1);
    }
    while (M--) {
        char cmd[10];
        int l, r, d;
        scanf("%s%d%d", cmd, &l, &r);
        l--; r--;
        if (cmd[0] == 'a') {
            scanf("%d", &d);
            for (int i = l; i <= r; i++) {
                if (L[A[i]])
                    add(i, -1);
                A[i] += d;
                if (L[A[i]])
                    add(i, 1);
            }
        } else {
            printf("%d\n", sum(r) - sum(l-1));
        }
    }

    return 0;
}
