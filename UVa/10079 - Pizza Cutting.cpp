#include <stdio.h>
int main(void)
{
	int n;
	long long int sum;
	
	while(EOF != scanf("%d", &n) && n >= 0) {
		
		sum = 1;
		
		sum += (long long)n*(long long)(1+n)/2;
		
		printf("%lld\n", sum);
		
	}
	
	return 0;
}