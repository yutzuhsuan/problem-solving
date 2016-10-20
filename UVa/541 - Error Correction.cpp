#include <stdio.h>
#include <string.h>
int main(void)
{
	int n;
	int m[105][105];
	int row, col, error;
	
	while(EOF != scanf("%d", &n) && n) {
		memset(m, 0, sizeof(m));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) {
				scanf("%d", &m[i][j]);
				if(m[i][j]) {
					m[i][0]++;
					m[0][j]++;
				}
			}
		
		error = 0;
		row = 0;
		col = 0;
		for(int i = 1; i <= n; i++) {
			if(m[i][0]%2) {
				if(!row)
					row = i;
				else
					error = 1;
			}
			if(m[0][i]%2) {
				if(!col)
					col = i;
				else
					error = 1;
			}
			if(error)
				break;
		}
		
		if(error || (!row && col) || (row && !col))
			printf("Corrupt\n");
		else if(!row && !col)
			printf("OK\n");
		else
			printf("Change bit (%d,%d)\n", row, col);
		
	}
	
	return 0;
}