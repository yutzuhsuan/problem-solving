#include <stdio.h>
#include <algorithm>
using namespace std;

int m[105][105];
int main(void)
{
	int C, S, Q, T = 1, x, y, d;

	while(EOF != scanf("%d %d %d", &C, &S, &Q) && C && S && Q) {
		
		
		for(int i = 0; i <= C; i++)
			for(int j = 0; j <= C; j++)
				m[i][j] = 99999999;
		
		for(int i = 0; i <= C; i++)
			m[i][i] = 0;
		
		while(S--) {
			scanf("%d %d %d", &x, &y, &d);
			m[x][y] = d;
			m[y][x] = d;
		}
		
		for(int k = 1; k <= C; k++)
			for(int i = 1; i <= C; i++)
				for(int j = 1; j <= C; j++)
					if(max(m[i][k], m[k][j]) < m[i][j])
						m[i][j] = max(m[i][k], m[k][j]);
		
		if(T != 1)
			puts("");
		printf("Case #%d\n", T++);
		
		while(Q--) {
			scanf("%d %d", &x, &y);
			if(m[x][y] != 99999999)
				printf("%d\n", m[x][y]);
			else
				printf("no path\n");
		}
		
	}

	return 0;
}