#include <stdio.h>
int prime[20000005] = {1, 1, 0};
int answer[100005] = {0};
int main(void)
{
	int cnt = 1;
	long long i, j;
	for(i = 3; i < 20000000 && cnt <= 100000; i += 2) {
		if(!prime[i]) {
			for(j = i * i; j < 20000000; j+=i)
				prime[j] = 1;
			if(!prime[i] && !prime[i-2])
				answer[cnt++] = i-2;
		}
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("(%d, %d)\n", answer[n], answer[n]+2);
	}

	return 0;
}