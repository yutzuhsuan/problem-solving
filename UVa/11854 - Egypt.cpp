#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	long long i, j, k;
	long long isq, jsq, ksq;
	
	while(EOF != scanf("%lld %lld %lld", &i, &j, &k) && (i || j || k)) {

		isq = i*i;
		jsq = j*j;
		ksq = k*k;
		
		if(isq == jsq+ksq)
			printf("right\n");
		else if(jsq == isq+ksq)
			printf("right\n");
		else if(ksq == isq+jsq)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}