#include <stdio.h>
int main(void)
{
	int n, ans, binary[35], cnt;
	
	while(EOF != scanf("%d", &n) && n) {
		ans = 0;
		cnt = 0;
		while(n) {
			ans += n%2;
			binary[cnt++] = n%2;
			n /= 2;
		}
		
		printf("The parity of ");
		for(int i = cnt-1; i >= 0; i--)
			printf("%d", binary[i]);
		printf(" is %d (mod 2).\n", ans);
	}

	return 0;
}