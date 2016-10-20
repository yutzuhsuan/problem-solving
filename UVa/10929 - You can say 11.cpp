#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void)
{
	int n;
	char s[1005];
	int sum[2];
	
	while(EOF != scanf(" %s", s)) {
		if(!strcmp(s, "0"))
			break;
		
		sum[0] = 0;
		sum[1] = 0;
		for(int i = 0; i < strlen(s); i++)
			sum[i%2] += s[i]-'0';
		if((abs(sum[0]-sum[1])%11))
			printf("%s is not a multiple of 11.\n", s);
		else
			printf("%s is a multiple of 11.\n", s);	
	}
	
	return 0;
}