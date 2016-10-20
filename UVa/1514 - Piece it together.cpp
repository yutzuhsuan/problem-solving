#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
struct Node {
    int y;
    int next;
} edge[1000005];
int e, head[250005];
void addEdge(int x, int y) {
    edge[e].y = y;
    edge[e].next = head[x], head[x] = e++;
}
int mx[250005], my[250005], used[250005];
int dfs(int now) {
    int i, x;
    for(i = head[now]; i != -1; i = edge[i].next) {
        x = edge[i].y;
        if(!used[x]) {
            used[x] = 1;
            if(my[x] == -1 || dfs(my[x])) {
                mx[now] = x, my[x] = now;
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int testcase, n, m;
    int i, j;
    scanf("%d", &testcase);
    char g[505][505];
    int node[505][505];
    while(testcase--) {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
            scanf("%s", g[i]);
        e = 0;
        memset(head, -1, sizeof(head));
        int B = 0, W = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(g[i][j] == 'W')
                    node[i][j] = W++;
                if(g[i][j] == 'B')
                    node[i][j] = B++;
            }
        }
        if(W != B*2) {
            puts("NO");
            continue;
        }
        int source = 0, sink = W + B*2 + 1;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(g[i][j] == 'B') {
                    if(j-1 >= 0 && g[i][j-1] == 'W')
                        addEdge(node[i][j], node[i][j-1]);
                    if(j+1 < m && g[i][j+1] == 'W')
                        addEdge(node[i][j], node[i][j+1]);
                    if(i-1 >= 0 && g[i-1][j] == 'W')
                        addEdge(node[i][j]+B, node[i-1][j]);
                    if(i+1 < n && g[i+1][j] == 'W')
                        addEdge(node[i][j]+B, node[i+1][j]);
                }
            }
        }
		/*
		for(i = 0; i < e; i++)
			printf("%d %d\n", edge[i].y, edge[i].next);
		puts("");
		for(i = 0; i < 2 * B; i++)
			printf("%d\n", head[i]);
		*/
		
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        int match = 0;
        B = B*2;
        for(i = 0; i < B; i++) {
            if(mx[i] == -1) {
                memset(used, 0, sizeof(used));
                if(dfs(i))
                    match++;
                else
                    break;
            }
        }
        puts(match == B ? "YES" : "NO");
    }
    return 0;
}