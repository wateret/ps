#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 123456789

char S[2200], T[2200];
int SL, TL;
int dp[2200];
int tr[2200];

struct TrieNode {
  TrieNode* children[26];
  int a, b;

  TrieNode(int a, int b) : a(a), b(b) {
    memset(children, 0, sizeof(children));
  }
  ~TrieNode() {
    for (int i = 0; i < 26; i++) {
      if (children[i])
        delete children[i];
    }
  }
  TrieNode* insert(const char c, int na, int nb) {
    int k = c-'a';
    if (children[k] == NULL)
      children[k] = new TrieNode(na, nb);
    return children[k];
  }
  TrieNode* next(const char c) {
    int k = c-'a';
    return children[k];
  }
};

TrieNode* ans[2200];

int main() {
  scanf("%s%s", S+1, T+1);
  SL = strlen(S+1);
  TL = strlen(T+1);
  TrieNode* trie = new TrieNode(0, 0);
  for (int i = 1; i <= SL; i++) {
    TrieNode* node = trie;
    for (int j = i; j <= SL; j++) {
      node = node->insert(S[j], i, j);
    }
    TrieNode* node2 = trie;
    for (int j = i; j > 0; j--) {
      node2 = node2->insert(S[j], i, j);
    }
  }
  for (int i = TL; i > 0; i--) {
    dp[i] = INF;
    TrieNode* node = trie;
    for (int j = i; j <= TL; j++) {
      if (node) {
        node = node->next(T[j]);
        int v = dp[j+1]+(node ? 1 : INF);
        if (v < dp[i]) {
          dp[i] = v;
          ans[i] = node;
          tr[i] = j+1;
        }
      }
    }
  }
  if (dp[1] >= INF) {
    printf("-1\n");
  } else {
    printf("%d\n", dp[1]);
    int i = 1;
    for (int j = 0; j < dp[1]; j++) {
      printf("%d %d\n", ans[i]->a, ans[i]->b);
      i = tr[i];
    }
  }

  return 0;
}