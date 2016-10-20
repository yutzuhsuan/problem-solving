#include <stdio.h>
int main(void)
{
	int B, N, D, C, V;
	int b[30];

	while(EOF != scanf("%d %d", &B, &N) && B && N) {

		for(int i = 1; i <= B; i++)
			scanf("%d", &b[i]);
			
		for(int i = 0; i < N; i++) {
			scanf("%d %d %d", &D, &C, &V);
			b[D] -= V;
			b[C] += V;
		}
		int flag = 1;
		for(int i = 1; i <= B; i++)
			if(b[i] < 0)
				flag = 0;

		if(flag)
			printf("S\n");
		else
			printf("N\n");



	}

	return 0;
}
