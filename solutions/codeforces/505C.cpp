#include <cstdio>
#include <map>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n,d;

int best[30001][500]; // base +250
int gem[30001];

int main(){
	memset(best, -1, sizeof(best));
	scanf("%d%d",&n,&d);
	for (int i = 0; i < n; i++) {
		int p;
		scanf("%d",&p);
		gem[p]++;
	}
	int ans = 0;
	best[d][250] = gem[d];
	for (int i = d; i <= 30000; i++) {
		for (int j = 0; j < 500; j++) {
			if (best[i][j] == -1) continue;
			int jump = j-250+d;
			int val = best[i][j];
			ans = max(ans, val);
			for (int df = max(1, jump-1); df <= jump+1; df++) {
				int next = i + df;
				if (next <= 30000) {
					best[next][df-d+250] = max(best[next][df-d+250], val + gem[next]);
				}
			}
		}
	}
	printf("%d\n",ans);
}
