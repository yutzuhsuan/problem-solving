#include <stdio.h>
int main(void)
{
	long long n, k;
	long long ans;
	
	while(EOF != scanf("%lld %lld", &n, &k) && (n || k)) {
		
		long long i, j;
		ans = 1;
		for(i = n, j = 1; i > (k > n-k ? k : n-k); i--, j++) {
			ans *= i;
			ans /= j;
		}
		
		printf("%lld\n", ans);
	}

	return 0;
}