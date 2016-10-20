#include <stdio.h>
#include <math.h>
int main(void)
{
	int N;
	int sqrt_N;
	int sum;
	printf("PERFECTION OUTPUT\n");
	while(EOF != scanf("%d", &N) && N) {
		sum = 0;
		sqrt_N = sqrt(N);
		
		for(int i = 1; i <= sqrt_N; i++)
			if(!(N%i))
				sum += i+N/i;
		
		if(sqrt_N*sqrt_N == N)
			sum -= sqrt_N;
		sum -= N;
		
		if(sum == N)
			printf("PERFECT\n");
		else if(sum < N)
			printf("DEFICIENT\n");
		else if(sum > N)
			printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}