#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct point
{
	int x, y;
};
queue <struct point> q;
char matrix[105][105];

void bfs(int a, int b)
{
	struct point P;
	P.x = a, P.y = b;
	matrix[a][b] = '0';
	q.push(P);

	while(!q.empty()) {
		struct point cur = q.front();
		q.pop();
		for(int i = -1; i <= 1; i++)
			for(int j = -1; j <= 1; j++)
				if(matrix[cur.x+i][cur.y+j] == '@') {
					matrix[cur.x+i][cur.y+j] = '0';
					struct point tmp;
					tmp.x = cur.x+i;
					tmp.y = cur.y+j;
					q.push(tmp);
				}

	}
	return ;
}

int main(void)
{
	int n, m;
	int ans;

	while(EOF != scanf("%d %d\n", &n, &m) && n && m) {
		ans = 0;
		for(int i = 0; i < 105; i++)
			for(int j = 0; j < 105; j++)
				matrix[i][j] = '0';
		
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf(" %c", &matrix[i][j]);

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(matrix[i][j] == '@') {
					bfs(i, j);
					ans++;
				}

		printf("%d\n", ans);
	}
	return 0;
}
