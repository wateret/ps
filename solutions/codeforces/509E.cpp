#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

typedef long long ll;

char A[1000000];
ll S[1000000];

int vowel(char c)
{
        switch (c) {
        case 'I':
        case 'E':
        case 'A':
        case 'O':
        case 'U':
        case 'Y':
                return 1;
        }
        return 0;
}

ll sumof(int l, int h)
{
        return S[h] - S[l-1];
}

int main()
{
        cin >> A;
        int L = strlen(A);

        S[0] = 0;
        for (int i = 0; i < L; i++) {
                S[i+1] = S[i] + vowel(A[i]);
        }

        double ress = 0.0;
        double resb = 0.0;
        ll acc = 0; //sumof(1, L);
        for (int i = 1; i <= L / 2; i++) {
                acc += sumof(i, L-i+1);
                ress += (double)acc / (double)i;
                resb += (double)acc / (double)(L-i+1);
        }
        if (L % 2 == 1) {
                int pi = L/2+1;
                acc += sumof(pi, pi);
                resb += (double)acc / (double)pi;
        }
        printf("%.10f\n", resb + ress);
        return 0;
}

