#include <stdio.h>

int f91(int x)
{
	if(x <= 100)
		return f91(f91(x+11));
	else
		return x-10;
}

int main(void)
{
	int n;
	
	while(EOF != scanf("%d", &n) && n)
		printf("f91(%d) = %d\n", n, f91(n));

	return 0;
}