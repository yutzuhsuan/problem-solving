#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime[46350] = {};
int prime_only[46350] = {};
int prime_only_square[46350] = {};
int prime_cnt;

void build_prime()
{
	for(int i = 2; i < 46345; i++)
		prime[i] = 1;
	for(int i = 2; i < 46345; i++)
		if(!prime[i])
			continue;
		else
			for(int j = i*2; j < 46345; j+=i)
				prime[j] = 0;
	prime_cnt = 0;
	for(int i = 2; i < 46345; i++)
		if(prime[i]) {
			prime_only[prime_cnt] = i;
			prime_only_square[prime_cnt] = i*i;
			prime_cnt++;
		}
	
	return ;
}
int is_prime(int x)
{
	
	if(x < 46341)
		return prime[x];
	
	int stop = sqrt(x) + 1;
	for(int i = 0; i < prime_cnt && prime_only_square[i] <= x; i++)
		if(!(x % prime_only[i]))
				return 0;
	
	return 1;
	
}

int main(void)
{
	
	unsigned int L, U;
	unsigned int max_len;
	unsigned int min_len;
	unsigned int max_a;
	unsigned int max_b;
	unsigned int min_a;
	unsigned int min_b;
	unsigned int pre;
	unsigned int cur;

	
	build_prime();

	
	while(EOF != scanf(" %d %d", &L, &U)) {
		max_len = 0;
		min_len = 2147483647;
		pre = -1;
		cur = -1;
		max_a = 0;
		max_b = 0;
		min_a = 0;
		min_b = 0;
		
		for(int i = L; i <= U && i > 0; i++) {
			if(!(i%2) && i != 2)
				continue;
			
			if(is_prime(i)) {
		
				pre = cur;
				cur = i;
				if(cur - pre > max_len && pre != -1) {
					max_len = cur - pre;
					max_a = pre;
					max_b = cur;
				}
				if(cur - pre < min_len && pre != -1) {
					min_len = cur - pre;
					min_a = pre;
					min_b = cur;
				}
			}
		}
		
		if(!max_a && !max_b && !min_a && !min_b)
			printf("There are no adjacent primes.\n");
		else
			printf("%d,%d are closest, %d,%d are most distant.\n", min_a, min_b, max_a, max_b);
	}
	return 0;
}