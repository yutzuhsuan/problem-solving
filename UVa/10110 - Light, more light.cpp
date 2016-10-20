#include <stdio.h>
#include <math.h>
int main(void)
{
	double n;
	
	while(EOF != scanf("%lf", &n) && n) {
		/*
		if(sqrt(n) - (int)sqrt(n) < 0.000000001)
			printf("yes\n");
		else
			printf("no\n");
		*/
		double a = pow(n, 1.0/2);
		if(a - (int)a < 0.0000000001)
			printf("yes\n");
		else
			printf("no\n");
		
	}
	
	
	return 0;
}