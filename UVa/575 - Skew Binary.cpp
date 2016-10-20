#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	char s[50];
	int s_len, cnt;
	long long int sum;
	
	while(gets(s) != NULL) {
		if(!strcmp(s, "0"))
			break;
		
		s_len = strlen(s);
		cnt = 1;
		sum = 0;
		for(int i = s_len-1; i >= 0; i--) {
			if(s[i] == '0') {
				cnt++;
				continue;
			}
			else
				sum += (long long)(s[i]-'0')*(pow(2, cnt++)-1);
		}
		printf("%lld\n", sum);
		
		
	}
	
	return 0;
}