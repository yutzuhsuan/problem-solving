/*******************************************************/
/* UVa 108 Maximum Sum                                 */
/* Version: 2015/02/10                                 */
/*******************************************************/
#include <stdio.h>
using namespace std;
int main(void)
{

	int N, a[105][105], column_sum[105][105], ans, sum;
	
	for(int i = 0; i < 105; i++)
		for(int j = 0; j < 105; j++) {
			a[i][j] = 0;
			column_sum[i][j] = 0;
		}
	
	while(EOF != scanf(" %d", &N)) {
	
	
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				scanf(" %d", &a[i][j]);
		/*
		puts("");
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++)
					printf("%d ", a[i][j]);
			puts("");
		}
		*/
			
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				column_sum[i][j] = column_sum[i-1][j] + a[i][j];
		ans = -1e9;
		for(int i = 1; i <= N; i++)
			for(int j = i; j <= N; j++) {
				sum = 0;
				for(int k = 1; k <= N; k++) {
					sum += column_sum[j][k] - column_sum[i-1][k];
					if(sum > ans) ans = sum;
					if(sum < 0) sum = 0;
				}
			}
			
		printf("%d\n", ans);
	}

	return 0;
}