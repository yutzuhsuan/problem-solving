#include <stdio.h>
int main(void)
{
	int a, b;
	
	while(EOF != scanf("%d %d", &a, &b) && (a != -1 && b != -1)) {
		
		if(a > b) {
			int tmp;
			tmp = a;
			a = b;
			b = tmp;
		}
	
		printf("%d\n", b-a < a+100-b ? b-a : a+100-b);
	
	}

	return 0;
}