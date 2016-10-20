#include <stdio.h>
int main(void)
{
	int T;
	
	long long int s, d, a;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld", &s, &d);
		
		a = (s+d)/2;
		
		if(a > s || a < s-a || (s+d)%2)
			printf("impossible\n");
		else
			printf("%lld %lld\n", a, s-a);
		
		
	}

	return 0;
}