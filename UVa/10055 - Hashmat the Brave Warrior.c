#include <stdio.h>
int main(void)
{
	long long n, m;
	
	while(EOF != scanf("%lld %lld", &n, &m)) 
		printf("%lld\n", n > m ? n-m : m-n);
	
	return 0;
}