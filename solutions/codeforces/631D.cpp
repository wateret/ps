#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll, char> llc;

int N, M;
vector<llc> A, B;

bool incl(llc& s, llc& k)
{
  return s.second == k.second && s.first >= k.first;
}

int KMP(vector<llc>& S, vector<llc>& K)
{
  vector<int> T(K.size() + 1, -1);
  vector<int> matches;

  for (int i = 1; i <= K.size(); i++)
  {
    int pos = T[i - 1];
    while (pos != -1 && !incl(K[i-1], K[pos]))
//    while (pos != -1 && K[pos] != K[i - 1])
      pos = T[pos];
    T[i] = pos + 1;
  }

  int sp = 0;
  int kp = 0;
  int f = 0;
  while(sp < S.size())
  {
    while(kp != -1 && (kp == K.size() || (K[kp] != S[sp] && !((kp == 0 || kp == K.size()-1) && incl(S[sp], K[kp]))))) {
      kp = T[kp];
      if (f) {
        kp--;
        sp--;
        f = 0;
      }
    }
    kp++;
    sp++;
    if(kp == K.size()) {
      if (incl(S[sp-1], K[kp-1]))
        f = 1;
      matches.push_back(sp - K.size());
    }
  }

  return matches.size();
}

void input(vector<llc>& o, int l) {
  ll nn;
  char cc;
  scanf("%lld-%c", &nn, &cc);
  l--;
  while (l--) {
    ll n;
    char c;
    scanf("%lld-%c", &n, &c);
    if (c == cc) {
      nn += n;
    } else {
      o.push_back(make_pair(nn, cc));
      cc = c;
      nn = n;
    }
  }
  o.push_back(make_pair(nn, cc));
}

int main() {
  scanf("%d%d", &N, &M);
  input(A, N);
  input(B, M);

  ll ans = 0;
  if (B.size() > 1) {
    ans = KMP(A, B);
  } else {
    for (int i = 0; i < A.size(); i++)
      if (A[i].second == B[0].second && A[i].first >= B[0].first)
        ans += A[i].first - B[0].first + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
