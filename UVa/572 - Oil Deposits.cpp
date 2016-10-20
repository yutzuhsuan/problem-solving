#include <stdio.h>
#include <string.h>

int fib[5005][50];
int main(void)
{
	
	int flag;
	memset(fib, 0, sizeof(fib));
	
	f[1][0] = 1;
	f[2][0] = 1;
	
	for(int i = 3; i <= 5000; i++)
		for(int j = 0; j <= 50; j++) {
			fib[i][j] = fib[i-1][j]+fib[i-2][j];
			fib[i][j+1] += fib[i][j]/10000;
			fib[i][j] %= 10000;
		}
	
	while(EOF != scanf("%d", &n)) {
		flag = 0;
		printf("The Fibonacci number for %d is", n);
		for(int i = 50; i >= 0; i--) {
			if(fib[n][i] != 0 && !flag) {
				printf("%d", fib[n][i]);
				flag = 1;
				continue;
			}
			if(flag)
				printf("%4d", fib[n][i]);
		}
		puts("");		
	}
	
	return 0;
}