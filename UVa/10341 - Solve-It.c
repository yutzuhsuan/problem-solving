#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int p, q, r, s, t, u;
int flag;

double test(double x)
{
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2) + u;
}

int main(void)
{
	double L, R, mid, ans;

	

	while(EOF != scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u)) {

		L = 0.0;
		R = 1.0;
		flag = 0;
		
		
		while(R- L > 0.0000001f) {
			mid = (L + R) / 2;
			
			ans = test(mid);
		
			
			if(ans < 0)
				R = mid;
			else
				L = mid;

				
		}

		if(test(1)*test(0) > 0)
			printf("No solution\n");
		else
			printf("%.4lf\n", mid);
	
	}
	return 0;
}