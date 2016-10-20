#include <stdio.h>
int main(void)
{
	int N, cnt;
	int ternary[20];
	
	while(EOF != scanf("%d", &N) && N >= 0) {
		cnt = 0;
		if(!N)
			printf("0");
		
		while(N != 0) {
			ternary[cnt++] = N%3;
			N /= 3;
		}
		
		for(int i = cnt-1; i >= 0; i--)
			printf("%d", ternary[i]);
		puts("");
	}

	return 0;
}