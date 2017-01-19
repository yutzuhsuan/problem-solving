#include <stdio.h>
int main(void)
{
	int sum, ans, T = 1, n;
	
	while(EOF != scanf("%d", &n) && n > 0) {
		ans = 0;
		sum = 1;
		while(sum < n) {
			sum *= 2;
			ans++;
		}
		
		printf("Case %d: %d\n", T++, ans);
		
	}
	
	return 0;
}