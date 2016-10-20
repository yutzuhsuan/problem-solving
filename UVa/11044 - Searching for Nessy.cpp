#include <stdio.h>
#include <math.h>
int main(void)
{
	int t, n, m;
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		printf("%.0lf\n", ceil((double)(n-2)/3)*ceil((double)(m-2)/3));
	}

	return 0;
}