#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define MAXN 1000100
int N, MEM[5000100];
int A[MAXN];
vector<int> li;

void dfs(int n, int p, int v)
{
    if (p == (1 << 22)) {
        MEM[n] = v;
        return;
    }
    if (MEM[n] != 0)
        return;

    int np = p << 1;
    if ((n&p) == 0) { // if the bit is 0
        dfs(n|p, np, v);
    }
    dfs(n, np, v);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int v;
        scanf("%d", &v);
        A[i] = v;
        dfs(A[i], 1, A[i]);
    }

    for (int i = 0; i < N; i++) {
        int d = (~A[i]) & ((1<<22)-1);
        printf("%d", MEM[d] == 0 ? -1 : MEM[d]);
        putchar(i == N-1 ? '\n' : ' ');
    }

    return 0;
}