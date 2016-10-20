#include <stdio.h>
#include <math.h>

int find(int x)
{
	int cnt, ret = 1;
	int i = 2;
	
	while(x != 1){
		cnt = 0;
		if(sqrt(x) < i){
			ret *= 2;
			break;
		}
		
		while(!(x % i)) {
			x /= i;
			cnt++;
		}
		ret *= (cnt+1);
		i++;
	}
	return ret;
}
int main(void)
{
	int N, L, U;
	int ans;
	int max_divisors, divisors;
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &L, &U);
		divisors = 0;
		ans = 0;
		max_divisors = 0;
	
		for(int i = L; i <= U; i++) {
			divisors = find(i);
			if(divisors > max_divisors) {
				max_divisors = divisors;
				ans = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, ans, max_divisors);
	}
	return 0;
}