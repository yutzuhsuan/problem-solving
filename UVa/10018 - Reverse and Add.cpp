#include <stdio.h>

unsigned int reverse(unsigned int num)
{
	int i;
	unsigned int x = 0;
	
	for(i = 0;num != 0; i++) {
		x *= 10;
		x += num%10;
		num /= 10;
	}
	return x;
}

int main(void)
{
	int N,cnt;
	unsigned int number, r;
	
	scanf("%d", &N);
	while(N--) {
		scanf("%u", &number);
	
		cnt = 0;
		while(1) {
			r = reverse(number);
			if(r == number)
				break;
			else {
				number += r;
				cnt++;
			}
		}
		
		printf("%d %u\n", cnt, number);
	}
	
	return 0;
}