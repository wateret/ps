#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
typedef long long ll;

#define LEN(i) (C[i][2]-C[i][1])
int N;
int C[1000010][3];

int main()
{
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
                int x;
                scanf("%d", &x);
                C[x][0]++;
                if (C[x][1] == 0)
                        C[x][1] = i;
                C[x][2] = i;
        }
        int maxi = 0;
        for (int i = 0; i <= 1000000; i++)
                if (C[maxi][0] < C[i][0]
                        || (C[maxi][0] == C[i][0] && LEN(maxi) > LEN(i)))
                        maxi = i;
        printf("%d %d\n", C[maxi][1], C[maxi][2]);
        return 0;
}