#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int A[110][110];
int PSUM[110][110];
int CNT[110];
int V[110][110]; // V[i][j]
int cache[110][10010];
int sumof(int s, int l, int h) { return PSUM[s][h]-PSUM[s][l-1]; }

int f(int n, int m)
{
    if (n < 0)
        return 0;
    int& ret = cache[n][m];
    if (ret != -1)
        return ret;
    int maxv = -1000000000;
    for (int i = 0; i <= min(m, CNT[n]); i++)
        maxv = max(maxv, f(n-1, m-i)+V[n][i]);
    return ret = maxv;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> CNT[i];
        for (int j = 1; j <= CNT[i]; j++) {
            cin >> A[i][j];
            PSUM[i][j] = PSUM[i][j-1]+A[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        int cnt = CNT[i];
        for (int j = 0; j < cnt; j++) {
            int v = 1000000000;
            for (int k = 1; k <= cnt-j; k++)
                v = min(v, sumof(i, k, k+j));
            V[i][cnt-1-j] = sumof(i, 1, cnt)-v;
        }
        V[i][cnt] = sumof(i, 1, cnt);
    }
/*  for (int i = 0; i < N; i++) {
        for (int j = 0; j <= CNT[i]; j++)
            cout << V[i][j] << " ";
        cout << endl;
    }
    */
    cout << f(N-1, M) << endl;

    return 0;
}