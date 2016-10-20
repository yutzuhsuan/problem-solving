#include <stdio.h>
int main(void)
{
	int T, n, sum, ans;
	int num[1005];
	double average;
	
	scanf("%d", &T);
	
	while(T--) {
		scanf("%d", &n);
	
		sum = 0;
		ans = 0;
		
		for(int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
			sum += num[i];
		}
		average = (double)sum/n;
	
		for(int i = 0; i < n; i++)
			if(average < num[i])
				ans++;
			
		printf("%.3lf%%\n", (double)ans/n*100);
	
	}
	
	return 0;
}