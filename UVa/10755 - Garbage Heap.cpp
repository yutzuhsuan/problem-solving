/*******************************************************/
/* UVa 10755 - Garbage Heap                            */
/* Version: 2015/02/11                                 */
/* 想法：三維空間，枚舉二維平面						   */
/*				   另外一維用一維區間最大值求解        */
/*******************************************************/
#include <stdio.h>
int main(void)
{
	int N, A, B, C, i, j, k, l, m;
	long long a[25][25][25];
	long long tmp, total, sum, ans;
	
	for(i = 0; i < 25; i++)
		for(j = 0; j < 25; j++)
			for(k = 0; k < 25; k++)
				a[i][j][k] = 0;
	
	scanf(" %d", &N);
	while(N--) {
		total = 0;
		scanf(" %d %d %d", &A, &B, &C);
		for(i = 1; i <= A; i++)
			for(j = 1; j <= B; j++)
				for(k = 1; k <= C; k++) {
					scanf(" %lld", &tmp);
					total += tmp;
					a[i][j][k] = tmp + a[i][j-1][k] + a[i][j][k-1] - a[i][j-1][k-1];
				}
				
		/*
		for(i = 1; i <= A; i++) {
			for(j = 1; j <= B; j++)
				for(k = 1; k <= C; k++) {
					printf("%d ", a[i][j][k]);
				}
			puts("");
		}
		*/
		ans = total;
		for(i = 1; i <= B; i++)
			for(j = i; j <= B; j++)
				for(k = 1; k <= C; k++)
					for(l = k; l <= C; l++) {
						sum = 0;
						for(m = 1; m <= A; m++) {
							sum += a[m][j][l] - a[m][i-1][l] - a[m][j][k-1] + a[m][i-1][k-1];
							if(sum > ans) ans = sum;
							if(sum < 0) sum = 0;
						}
					}
			
		printf("%lld\n", ans);
		if(N) 
			puts("");
	}
	return 0;
}














