#include <stdio.h>
int main(void)
{
	int n, m;
	while(EOF != scanf("%d %d", &n, &m))
		printf("%d\n", n*m*2);
	return 0;
}