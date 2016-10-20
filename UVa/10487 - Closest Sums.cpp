#include <stdio.h>

int main(void)
{
	int n, m, q;
	long long num[1005];
	int case_cnt = 1;
	long long min;
	long long ans;
	
	while(scanf("%d", &n) != EOF && n) {
		printf("Case %d:\n", case_cnt++);
		for(int i = 0; i < n; i++)
			scanf("%lld", &num[i]);
		scanf("%d", &m);
		
		for(int i = 0; i < m; i++) {
			scanf("%d", &q);
			min = 1e9;
			for(int j = 0; j < n-1; j++)
				for(int k = j+1; k < n; k++) {
					if(num[k] + num[j] >= q && num[k] + num[j] - q < min) {
						min = num[k] + num[j] - q;
						ans = num[k] + num[j];
					}
					if(num[k] + num[j] < q && q - (num[k] + num[j]) < min) {
						min = q - (num[k] + num[j]);
						ans = num[k] + num[j];
					}
				}
			printf("Closest sum to %d is %d.\n", q, ans); 
		}
		
		
	}

	return 0;
}