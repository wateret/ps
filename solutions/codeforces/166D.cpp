#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <tuple>
using namespace std;

typedef long long ll;

#define INF 1100000000ll

struct Data {
    int size, cost, index;
    Data(int size, int cost, int index)
        : size(size), cost(cost), index(index) {}
    Data() {}
};

struct Comp {
    bool operator() (const Data& d1, const Data& d2) {
        return d1.size < d2.size;
    }
};

int N, M;
Data S[100010], C[100010];
int G[100010][2];
ll MEM[100010][2][2];
tuple<int, int, int> P[100010][2][2];

void connectEdge(int si, int ci) {
    int s = S[si].size;
    int c = S[si].cost;
    int l = C[ci].size;
    int d = C[ci].cost;
    if (d < c) return;
    if (s == l)
        G[ci][0] = si;
    if (s == l+1)
        G[ci][1] = si;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int c, s;
        cin >> c >> s;
        S[i] = Data(s, c, i);
    }
    S[N+1] = Data(INF, INF, N+1);
    cin >> M;
    for (int i = 1; i <= M; i++) {
        int d, l;
        cin >> d >> l;
        C[i] = Data(l, d, i);
    }
    C[M+1] = Data(INF, INF, M+1);
    sort(S+1, S+N+1, Comp());
    sort(C+1, C+M+1, Comp());
    for (int i = 1, j = 1; i <= M; i++) {
        int l = C[i].size;
        int d = C[i].cost;
        while (j <= N && !(S[j].size >= l))
            j++;
        if (j > N)
            break;
        connectEdge(j, i);
        connectEdge(j+1, i);
    }

    for (int i = M; i > 0; i--) {
        int ni = i+1;
        int aa = G[i][0];
        int bb = G[i][1];
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ll& ans = MEM[i][j][k];
                tuple<int, int, int>& path = P[i][j][k];
                int l = C[i].size;
                int nl = C[ni].size;
                int na[3], nb[3];
                if (l == nl) {
                    na[0] = j; nb[0] = k;
                    na[1] = 0; nb[1] = k;
                    na[2] = j; nb[2] = 0;
                } else if (l+1 == nl) {
                    na[0] = k; nb[0] = 1;
                    na[1] = k; nb[1] = 1;
                    na[2] = 0; nb[2] = 1;
                } else {
                    na[0] = 1; nb[0] = 1;
                    na[1] = 1; nb[1] = 1;
                    na[2] = 1; nb[2] = 1;
                }

                ans = MEM[ni][na[0]][nb[0]];
                path = make_tuple(0, na[0], nb[0]);
                if (j&&aa) {
                    ll nret = MEM[ni][na[1]][nb[1]] + S[aa].cost;
                    if (ans < nret) {
                        ans = nret;
                        path = make_tuple(1, na[1], nb[1]);
                    }
                }
                if (k&&bb) {
                    ll nret = MEM[ni][na[2]][nb[2]] + S[bb].cost;
                    if (ans < nret) {
                        ans = nret;
                        path = make_tuple(2, na[2], nb[2]);
                    }
                }
            }
        }
    }
    cout << MEM[1][1][1] << endl;

    int a=1, b=1;
    vector< pair<int, int> > ans;
    for (int i = 1; i <= M; i++) {
        auto p = P[i][a][b];
        a = get<1>(p);
        b = get<2>(p);
        int path = get<0>(p);
        if (path != 0)
            ans.push_back(make_pair(C[i].index, S[G[i][path-1]].index));
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
