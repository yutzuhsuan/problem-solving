#include <stdio.h>
int main(void)
{
	int n, k, ans;
	
	while(EOF != scanf("%d %d", &n, &k)) {
		ans = n;
		while(n/k != 0) {
			ans += n/k;
			n = n/k + n%k;
		}
		printf("%d\n", ans);
	}

	return 0;
}