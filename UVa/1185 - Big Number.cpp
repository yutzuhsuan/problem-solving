#include <stdio.h>
#include <math.h>
int DP[10000005] = {};
int main(void)
{
	double sum = 0;
	int T, n;

	for(int i = 1; i <= 10000000; i++) {
		sum += log10(i);
		DP[i] = (int)sum;
	}

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		printf("%d\n", DP[n]+1);
	}
	return 0;
}