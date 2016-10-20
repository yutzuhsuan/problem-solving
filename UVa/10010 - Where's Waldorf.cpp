#include <stdio.h>
#include <string.h>
int dir[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
int main(void)
{
	int kase, n, m, k, px, py, flag = 0, hasAns;
	char trash;
	
	char matrix[60][60], q[100];
	
	scanf("%d", &kase);
	
	while(kase--) {
		if(flag)
			puts("");
		else
			flag = 1;
		
		scanf("%d %d", &n, &m);
		scanf("%c", &trash);
		
		for(int i = 0; i < n; i++)
			gets(matrix[i]);
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(matrix[i][j] >= 'A' && matrix[i][j] <= 'Z')
					matrix[i][j] = matrix[i][j]-'A'+'a';
		
		
		scanf("%d", &k);
		scanf("%c", &trash);
		while(k--) {
			gets(q);
			
			for(int i = 0; i < strlen(q); i++)
				if(q[i] >= 'A' && q[i] <= 'Z')
					q[i] = q[i]-'A'+'a';
			
			//printf("%s\n", q);
			hasAns = 0;
			for(int i = 0; i < n && !hasAns; i++)
				for(int j = 0; j < m && !hasAns; j++) 
					if(matrix[i][j] == q[0]) {
						//printf("%d %d\n", i, j);
						for(int x = 0; x < 8; x++) {
							px = i+dir[x][0], py = j+dir[x][1];
							for(int y = 1; y < strlen(q); y++) {
								if(px < 0 || px >= n || py < 0 || py >= m)
									break;
								//printf("%c %c\n", matrix[px][py], q[y]);
								if(matrix[px][py] != q[y])
									break;
								if(y == strlen(q)-1) {
									printf("%d %d\n", i+1, j+1);
									hasAns = 1;
								}
								px += dir[x][0], py += dir[x][1];
							}
							if(hasAns)
								break;
						}
						if(strlen(q) == 1) {
							printf("%d %d\n", i+1, j+1);
							hasAns = 1;
						}
					}
			
		}
	}
	
	return 0;
}