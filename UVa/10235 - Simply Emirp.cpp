#include <stdio.h>
int prime[1000005] = {};

int main(void)
{
	
	for(int i = 3; i <= 1000000; i++) {
		if(prime[i])
			continue;
		for(int j = i*2; j <= 1000000; j+=i)
			prime[j] = 1;
	}
	
	int n;
	while(EOF != scanf("%d", &n)) {
		int n_reverse = 0, tmp = n;
		
		while(tmp != 0) {
			n_reverse *= 10;
			n_reverse += tmp%10;
			tmp /= 10;	
		}
		//printf("%d\n", n_reverse);
		if(n_reverse == n && !prime[n])
			printf("%d is prime.\n", n);
		else if(!prime[n_reverse] && !prime[n])
			printf("%d is emirp.\n", n);
		else if(!prime[n])
			printf("%d is prime.\n", n);
		else
			printf("%d is not prime.\n", n);
		
	}
	return 0;
}