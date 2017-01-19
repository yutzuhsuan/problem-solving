#include <stdio.h>
#include <string.h>
int main(void)
{
	int n, m, cnt, T = 1;
	char trash;
	char field[105][105];
	int ans[105][105];

	while(EOF != scanf("%d %d", &n, &m) && (n || m)) {
		
		scanf("%c", &trash);
		
		memset(ans, 0, sizeof(ans));
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%c", &field[i][j]);
				if(field[i][j] == '*')
					for(int k = -1; k <= 1; k++)
						for(int l = -1; l <= 1; l++)
							ans[i+k][j+l]++;
			}
			scanf("%c", &trash);
		}
		
		if(T != 1)
			puts("");
		printf("Field #%d:\n", T++);
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++)
				if(field[i][j] == '*')
					printf("*");
				else
					printf("%d", ans[i][j]);
			puts("");
		}

	}

	return 0;
}