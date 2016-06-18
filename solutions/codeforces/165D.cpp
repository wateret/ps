#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define MAXN 100100

int N, M;
vector<int> G[MAXN];
int EA[MAXN];
int EB[MAXN];
int WGROUP[MAXN];
map<int, int> GROUP[MAXN];
set<int> WHITE[MAXN];

bool VD[MAXN];

bool path(int g, int ca, int cb)
{
    if (ca > cb)
        swap(ca, cb);
    int nextwhite = *(WHITE[g].upper_bound(ca-1));
    if (nextwhite < cb)
        return false;
    return true;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        EA[i] = a;
        EB[i] = b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // find proxy vertex
    int proxy = 0;
    int maxdeg = 0;
    for (int i = 1; i <= N; i++) {
        int t = G[i].size();
        if (maxdeg < t) {
            maxdeg = t;
            proxy = i;
        }
    }

    // calc groups, number elements
    WGROUP[proxy] = -1;
    VD[proxy] = true;
    for (int i = 0; i < G[proxy].size(); i++) {
        WHITE[i].insert(-1000000);
        WHITE[i].insert(1000000);
        GROUP[i][proxy] = 0; // proxy is 0 for all groups
        int v = G[proxy][i];
        int no = 1;
        while (true) {
            GROUP[i][v] = no;
            WGROUP[v] = i;
            VD[v] = true;
            if (G[v].size() == 1)
                break;
            v = VD[G[v][0]] ? G[v][1] : G[v][0];
            no++;
        }
    }

    scanf("%d", &M);
    while (M--) {
        int type;
        scanf("%d", &type);
        if (type == 3) {    // find query
            int a, b;
            scanf("%d%d", &a, &b);

            int ans = -1;
            if (a == b) {
                ans = 0;
            } else {
                int ga = WGROUP[a], gb = WGROUP[b];
                if (ga == -1) ga = gb;
                if (gb == -1) gb = ga;
                int ca = GROUP[ga][a], cb = GROUP[gb][b];

                if (ga == gb) { // same group
                    if (path(ga, ca, cb))
                        ans = abs(ca-cb);
                } else { // different group
                    if (path(ga, ca, 0) && path(gb, cb, 0))
                        ans = ca+cb;
                }
            }
            printf("%d\n", ans);
        } else {    // black/white query
            int idx;
            scanf("%d", &idx);
            int a = EA[idx], b = EB[idx];

            int ga = WGROUP[a], gb = WGROUP[b];
            if (ga == -1) ga = gb;
            if (gb == -1) gb = ga;
            int ca = GROUP[ga][a], cb = GROUP[gb][b];

            if (ca > cb)
                swap(ca, cb);
            if (type == 2)
                WHITE[ga].insert(ca);
            else
                WHITE[ga].erase(ca);
        }
    }

    return 0;
}