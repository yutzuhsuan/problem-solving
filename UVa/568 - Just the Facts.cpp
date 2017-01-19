#include <stdio.h>
int digit[10005];
int main(void)
{
	digit[1] = 1;
	for(int i = 2; i <= 10000; i++) {
		digit[i] = digit[i-1]*i;
		//printf("%d %d\n", i, digit[i]);
		while(!(digit[i]%10))
			digit[i] /= 10;
		digit[i] %= 100000;
	}
	
	int n;
	while(EOF != scanf("%d", &n))
		printf("%5d -> %d\n", n, digit[n]%10);
	
	return 0;
}