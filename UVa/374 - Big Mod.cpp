#include <stdio.h>

long long recur(long long B, long long P, long long M)
{
	
	if(P == 1)
		return B%M;
	if(!P)
		return 1;
	
	long long tmp;
	if(P%2)
		tmp = recur(B, (P-1)/2, M);
	else
		tmp = recur(B, P/2, M);
	
	
	if(P%2)
		return (((tmp*tmp)%M)*(B%M))%M;
	else
		return (tmp*tmp)%M;
}

int main(void)
{
	long long B, P, M;
	long long ans;
	
	while(EOF != scanf("%lld", &B)) {
		scanf("%lld %lld", &P, &M);
		printf("%lld\n", recur(B, P, M));
	}

	return 0;
}