#include <stdio.h>
#include <string.h>

int num[1005][1005] = {};
int main(void)
{
	int n;
	int i, j;
	int flag;
	
	for(i = 0; i < 1005; i++) {
		num[i][0] = 1;
		for(j = 1; j < 1005; j++)
			num[i][j] = 0;
	}

	for(i = 1; i <= 1000; i++) {

		
		for(j = 0; j < 1005; j++) {
			num[i][j] *= i;
		}
	
		for(j = 0; j < 1005; j++) {
			num[i][j+1] = num[i][j+1] + ((num[i][j] - (num[i][j] % 1000)) / 1000);
			num[i][j] %= 1000;
		}

		for(j = 0; j < 1005; j++) {
			num[i+1][j] = num[i][j];
		}		
	}

	
	
	while(EOF != scanf("%d", &n)) {
		flag = 0;
		printf("%d!\n", n);
		for(i = 1000; i >= 0; i--) {
			if(flag) {
				printf("%03d", num[n][i]);
			}
			else if(num[n][i] != 0) {
				flag = 1;
				printf("%d", num[n][i]);
			}
		}
		puts("");
		/*
		for(i = 0; i < 1005; i++)
			num[i] = 0;
		num[0] = 1;
	
		for(i = 1; i <= n; i++) {
			
			for(j = 0; j < 1005; j++) {
				num[j] *= i;
			}
		
			for(j = 0; j < 1005; j++) {
				num[j+1] = num[j+1] + ((num[j] - (num[j] % 1000)) / 1000);
				num[j] %= 1000;
			}
		}

		for(i = 1005; i >= 0; i--) {
			if(flag) {
				printf("%03d", num[i]);
			}
			else if(num[i] != 0) {
				flag = 1;
				printf("%d", num[i]);
			}
		}
		puts("");
		*/
	}
	
	return 0;
}