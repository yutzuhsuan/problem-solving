#include <stdio.h>
int main(void)
{
	int n, T = 1;
	int a[55];
	int sum, average;
	int ans;
	
	while(EOF != scanf("%d", &n) && n) {
		sum = 0;
		ans = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		average = sum/n;
		
		for(int i = 0; i < n; i++)
			if(a[i] > average)
				ans += a[i]-average;
		
		
		printf("Set #%d\n", T++);
		printf("The minimum number of moves is %d.\n\n", ans);
	}

	return 0;
}