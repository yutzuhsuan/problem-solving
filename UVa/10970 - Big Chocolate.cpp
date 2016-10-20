#include <stdio.h>
int main(void)
{
	int n, m;
	
	while(EOF != scanf("%d %d", &n, &m) && n && m)
		printf("%d\n", (n-1)+n*(m-1));
	return 0;
}