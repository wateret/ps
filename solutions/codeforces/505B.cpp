#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> G[100][100];
bool V[100][100];

bool dfs(int c, int idx, int dest)
{
        if (dest == idx)
                return true;
        if (V[c][idx])
                return false;
        V[c][idx] = true;
        for (int i = 0; i < G[c][idx].size(); i++)
                if (dfs(c, G[c][idx][i], dest))
                        return true;
        return false;
}

int main()
{
        cin >> N >> M;
        int a, b, c;
        for (int i = 0; i < M; i++) {
                cin >> a >> b >> c;
                a--; b--; c--;
                G[c][a].push_back(b);
                G[c][b].push_back(a);
        }

        int q;
        cin >> q;
        while (q--) {
                memset(V, 0, sizeof(V));
                int u, v;
                cin >> u >> v;
                u--; v--;
                int res = 0;
                for (int i = 0; i < M; i++) {
                        res += dfs(i, u, v) ? 1 : 0;
                }
                cout << res << endl;
        }

        return 0;
}

