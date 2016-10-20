#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 20005;

vector<int> g[N], scc[N];
int pre[N], lowlink[N], sccno[N], dfs_clock, scc_cnt;
stack<int> S;

void dfs_scc(int u) {
	pre[u] = lowlink[u] = ++dfs_clock;
	S.push(u);
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!pre[v]) {
			dfs_scc(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		} else if (!sccno[v])
			lowlink[u] = min(lowlink[u], pre[v]);
	}
	if (lowlink[u] == pre[u]) {
		scc_cnt++;
		while (1) {
			int x = S.top(); S.pop();
			sccno[x] = scc_cnt;
			if (x == u) break;
		}
	}
}

void find_scc(int n) {
	dfs_clock = scc_cnt = 0;
	memset(sccno, 0, sizeof(sccno));
	memset(pre, 0, sizeof(pre));
	for (int i = 0; i < n; i++)
		if (!pre[i]) dfs_scc(i);
}

int t, n, m, val[N];
vector<int> g2[N];

void build() {
	memset(val, 0, sizeof(val));
	for (int i = 1; i <= scc_cnt; i++)
		g2[i].clear();
	for (int u = 0; u < n; u++) {
		val[sccno[u]]++;
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j];
			if (sccno[u] != sccno[v])
				g2[sccno[u]].push_back(sccno[v]);
		}
	}
}

int dp[N];

int dfs(int u) {
	if (dp[u] != -1) return dp[u];
	dp[u] = val[u];
	for (int i = 0; i < g2[u].size(); i++) {
		int v = g2[u][i];
		dp[u] = max(dp[u], dfs(v) + val[u]);
	}
	return dp[u];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			g[i].clear();
		int u, v;
		while (m--) {
			scanf("%d%d", &u, &v);
			u--; v--;
			g[u].push_back(v);
		}
		find_scc(n);
		build();
		memset(dp, -1, sizeof(dp));
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, dfs(sccno[i]));
		printf("%d\n", ans);
	}
	return 0;
}