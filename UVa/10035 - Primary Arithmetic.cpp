#include <stdio.h>
int main(void)
{
	int a, b, carry, cnt;
	
	while(EOF != scanf("%d %d", &a, &b) && (a || b)) {
		
		cnt = 0;
		carry = 0;
		while(a || b) {
			if(a%10 + b%10 + carry >= 10)
				carry = 1;
			else
				carry = 0;
			
			a /= 10;
			b /= 10;
			
			cnt += carry;
		}
		if(!cnt)
			printf("No carry operation.\n");
		else if(cnt == 1)
			printf("%d carry operation.\n", cnt);
		else
			printf("%d carry operations.\n", cnt);

	}

	return 0;
}