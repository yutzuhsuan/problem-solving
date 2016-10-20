#include <stdio.h>
#include <string.h>
int main(void)
{
	
	int a, b;
	int m[105][105];
	int isUsed[105];
	int cnt;
	int sum;
	int T = 1;
	
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			m[i][j] = 1000000;
	memset(isUsed, 0, sizeof(isUsed));
	
	while(EOF != scanf("%d %d", &a, &b) && a && b) {
		cnt = 0;
		memset(isUsed, 0, sizeof(isUsed));
		m[a][b] = 1;
		
		isUsed[a] = 1;
		isUsed[b] = 1;
		cnt += 2;
		
		while(scanf("%d %d", &a, &b) && a && b) {
			m[a][b] = 1;
			if(!isUsed[a]) {
				cnt++;
				isUsed[a] = 1;
			}
			if(!isUsed[b]) {
				cnt++;
				isUsed[b] = 1;
			}
		}

		/*
		for(int i = 1; i <= 100; i++)
			for(int j = 1; j <= 100; j++)
				if(m[i][j])
					printf("%d %d\n", i, j);
		*/
		
		for(int i = 1; i <= 100; i++)
			m[i][i] = 0;

		for(int k = 1; k <= 100; k++)
			for(int i = 1; i <= 100; i++)
				for(int j = 1; j <= 100; j++)
					if(m[i][k] + m[k][j] < m[i][j])
						m[i][j] = m[i][k] + m[k][j];
		
		sum = 0;	
		for(int i = 1; i <= 100; i++)
			for(int j = 1; j <= 100; j++)
				if(m[i][j] < 1000)
					sum += m[i][j];
	
		//printf("%d %d\n", sum, cnt*(cnt-1));
		printf("Case %d: average length between pages = %.3lf clicks\n", T++, (double)sum/((double)cnt*(double)(cnt-1)));
		
		for(int i = 0; i <= 100; i++)
			for(int j = 0; j <= 100; j++)
				m[i][j] = 1000000;
		memset(isUsed, 0, sizeof(isUsed));
	}

	return 0;
}