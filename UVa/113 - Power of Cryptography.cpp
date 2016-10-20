#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	double ans;
	double p;
	double n;
	
	while(EOF != scanf("%lf", &n)) {
		scanf("%lf", &p);
		ans = pow(p, 1/n);
		printf("%.0lf\n", ans);
	}
	return 0;
}