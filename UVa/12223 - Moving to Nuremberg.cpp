#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define maxn 500005
using namespace std;

struct state {
	int v;
	long long w;
	//state(int v, long long w) : v(v), w(w) {}
	state (int v = 0, long long w = 0) {  
        this->v = v;  
        this->w = w;  
    }
};

long long dp[maxn];
long long cnt[maxn], ans, sum;
int n;
bool vis[maxn];
vector<state> g[maxn];

void dfsCnt(int num, long long w) {
	vis[num] = true;
	
	dp[1] += w * cnt[num];
	for(int i = 0; i <g[num].size(); i++) {
		state now = g[num][i];
		
		if(vis[now.v])
			continue;
		
		dfsCnt(now.v, now.w * 2 + w);
		cnt[num] += cnt[now.v];
	}

}
void dfsAns(int num) {
	vis[num] = true;
	ans = min(ans, dp[num]);
	
	for(int i = 0; i < g[num].size(); i++) {
		state now = g[num][i];
		if(vis[now.v])
			continue;
		dp[now.v] = dp[num] + (sum - 2 * cnt[now.v]) * now.w * 2;
		dfsAns(now.v);
	}
}

int main(void)
{
	int c, a, b, m;
	long long w;
	bool f = false;
	scanf(" %d", &c);
	while(c--) {
		sum = 0;
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(dp, 0, sizeof(dp));
		
		scanf(" %d", &n);
		for(int i = 0; i <= n; i++)
			g[i].clear();
	
		
		for(int i = 1; i < n; i++) {
			scanf(" %d %d %lld", &a, &b, &w);
			g[a].push_back(state(b, w));
			g[b].push_back(state(a, w));
		}
		
		scanf(" %d", &m);
		while(m--) {
			scanf(" %d %lld", &a, &w);
			sum += w;
			cnt[a] = w;
		}
		
		memset(vis, false, sizeof(vis));
		dfsCnt(1, 0);
		
		ans = dp[1];
		memset(vis, false, sizeof(vis));
		dfsAns(1);
		
		printf("%lld\n", ans);
		
		f = false;
		for(int i = 1; i <= n; i++)
			if(ans == dp[i]) {
				if(f)
					printf(" ");
				printf("%d", i);
				f = true;
			}
		puts("");
	}
	return 0;
}