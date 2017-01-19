#include <stdio.h>
int main(void)
{
	unsigned int a, b;
	unsigned int sum;
	unsigned int powOf2;
	
	while(EOF != scanf("%u %u", &a, &b)) {
		//printf("%u %u\n", a, b);
		sum = 0;
		powOf2 = 1;
		while(a != 0 || b != 0) {
			sum += (a%2+b%2)%2*powOf2;
			powOf2 *= 2;
			a >>= 1;
			b >>= 1;		
		}
		printf("%u\n", sum);
	}

	return 0;
}