#include <stdio.h>

int N, M;
char A[510][510];
int sr, sc, dr, dc;

bool valid(int r, int c)
{
    return !(r < 0 || r >= N || c < 0 || c >= M);
}

bool dfs(int r, int c, int f = 0)
{
    if (!valid(r, c))
        return false;
    if (r == dr && c == dc && A[r][c] == 'X' && f == 0)
        return true;
    if (A[r][c] == 'X' && f == 0)
        return false;
    A[r][c] = 'X';
    return dfs(r+1, c) || dfs(r-1, c) || dfs(r, c+1) || dfs(r, c-1);
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", A[i]);
    scanf("%d%d", &sr, &sc);
    scanf("%d%d", &dr, &dc);
    sr--; sc--; dr--; dc--;
    printf("%s\n", dfs(sr, sc, 1) ? "YES" : "NO");
    return 0;
}