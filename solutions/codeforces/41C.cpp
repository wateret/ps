#include <stdio.h>
#include <string.h>

char S[200];

int main() {
  scanf("%s", S);
  int l = strlen(S);
  bool at = false;
  for (int i = 0; i < l; i++) {
    if (i == 0) {
      printf("%c", S[i]);
    } else {
      if (strncmp(S+i, "at", 2) == 0 && i+1 != l-1) {
        if (!at) {
          at = true;
          printf("@");
          i += 1;
        } else {
          printf("%c", S[i]);
        }
      } else if (strncmp(S+i, "dot", 3) == 0 && i+2 != l-1) {
        printf(".");
        i += 2;
      } else {
        printf("%c", S[i]);
      }
    }
  }
  printf("\n");

  return 0;
}