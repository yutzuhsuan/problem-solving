#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	
	long long ans, n, m, tmp;
	
	while(EOF != scanf("%lld %lld", &n, &m) && n && m) {
		if(n > m) {
			tmp = n;
			n = m;
			m = tmp;
		}
		ans = n*m*(n-1+m-1) + 4*(2*(n*(n-1)*(n-2)/6) + (m-n+1)*n*(n-1)/2);
		printf("%lld\n", ans);
	}
	
	return 0;
}