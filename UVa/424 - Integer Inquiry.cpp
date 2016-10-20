#include <stdio.h>
#include <string.h>
#include <math.h>

int p[5] = {1, 10, 100, 1000, 10000};
int main(void)
{
	char s[105];
	int cnt;
	int max_cnt = 0;
	int num[25];
	int sum[25];
	
	memset(sum, 0, sizeof(sum));
	
	while(gets(s) != NULL) {
		if(!strcmp(s, "0"))
			break;
		
		memset(num, 0, sizeof(num));
		
		cnt = 0;

		for(int i = strlen(s)-1, j = 0; i >= 0; i--, j++) {
			if(j == 5) {
				j = 0;
				cnt++;
			}
			num[cnt] = num[cnt]+(s[i]-'0')*p[j];
		}
		
		if(cnt > max_cnt)
			max_cnt = cnt;
		
		for(int i = 0; i <= max_cnt; i++) {
			sum[i] += num[i];
			sum[i+1] += sum[i]/100000;
			if(sum[i+1] != 0 && i+1 > max_cnt)
				max_cnt = i+1;
			sum[i] %= 100000;
		}	
	}

	for(int i = max_cnt; i >= 0; i--)
		if(i == max_cnt)
			printf("%d", sum[i]);
		else
			printf("%05d", sum[i]);
	puts("");
	return 0;
}