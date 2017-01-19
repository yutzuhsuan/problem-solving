#include <stdio.h>
int main(void)
{
	int n, tmp;
	
	while(EOF != scanf("%d", &n) && n) {
	
		while(n/10 != 0) {
			tmp = 0;
			while(n) {
				tmp += n%10;
				n /= 10;
			}
			n = tmp;
		}
		
		printf("%d\n", n);
	}
	
	return 0;
}