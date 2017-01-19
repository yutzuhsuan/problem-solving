#include <stdio.h>
#include <string.h>
#include <math.h>
int tmp[250];
int pri[200];
int pri_cnt;
int pri_sum[200];

int main(void)
{
	int N;
	
	memset(tmp, 0, sizeof(tmp));
	pri_cnt = 0;
	for(int i = 2; i < 250; i++)
		if(!tmp[i]) {
			for(int j = i; j < 250; j += i)
				tmp[j] = 1;
			pri[pri_cnt++] = i;
		}
	printf("PERFECTION OUTPUT\n");
	while(EOF != scanf("%d", &N) && N) {
	
		int N2 = N;
		
		memset(pri_sum, 0, sizeof(pri_sum));
		printf("%5d  ", N);
		
		int cnt = 0;
		while(N != 1 && cnt < pri_cnt) {
			
			while(!(N%pri[cnt])) {
				N /= pri[cnt];
				pri_sum[cnt]++;
			}
			cnt++;
		}
		//printf(" %d ", cnt);
		int tmp_sum;
		int sum = 1;
		for(int i = 0; i < 200; i++)
			if(pri_sum[i]) {
				tmp_sum = 0;
				for(int j = 0; j <= pri_sum[i]; j++) {
					tmp_sum += pow(pri[i], j);
					//printf("\n %d %d \n", pri[i], j); 
				}
				//printf("\n%d %d %d\n", pri[i], tmp_sum, pri_sum[i]);
				sum *= tmp_sum;
			}
		sum -= N2;
		//printf("%d %d\n", sum, N2);
		if(sum == N2)
			printf("PERFECT\n");
		else if(sum < N2)
			printf("DEFICIENT\n");
		else if(sum > N2)
			printf("ABUNDANT\n");

	}
	printf("END OF OUTPUT\n");
	return 0;
}