#include <stdio.h>
#include <string.h>

int N;
int A[100010];
bool err = false;
int t = 0;
int l = 0;
char ab[1000000];
int p = 0;;

void parseType()
{
        if (t >= l) {
                err = true;
                return;
        }
        t++;
        if (A[t-1] == 'p') {
                strcpy(ab+p, "pair<"); p += 5;
                parseType();
                strcpy(ab+p, ","); p += 1;
                parseType();
                strcpy(ab+p, ">"); p += 1;
        }
        else {
                strcpy(ab+p, "int"); p += 3;
        }
}

int main()
{
        scanf("%d", &N);
        while (true) {
                char buf[10];
                if (scanf("%s", buf) != 1)
                        break;
                A[l] = buf[0];
                l++;
        }
        parseType();
        printf("%s\n", (!err && t == l ? ab : "Error occurred"));

        return 0;
}
