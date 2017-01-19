#include <stdio.h>
int main(void)
{
	int fib[55];
	
	fib[0] = 1;
	fib[1] = 1;
	
	for(int i = 2; i <= 50; i++)
		fib[i] = fib[i-1]+fib[i-2];
	
	int n;
	while(EOF != scanf("%d", &n) && n)
		printf("%d\n", fib[n]);
	
	return 0;
}