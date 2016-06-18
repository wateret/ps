#include <stdio.h>

int A[10] = { 2, 7, 2, 3, 3, 4, 2, 5, 1, 2 };

int main()
{
  char a, b;
  scanf("%c%c", &a, &b);
  printf("%d\n", A[a-'0']*A[b-'0']);
  return 0;
}
