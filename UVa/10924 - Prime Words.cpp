#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[25];
	int sum;
	int pri[1300];
	
	memset(pri, 0, sizeof(pri));
	pri[0] = 1;
	pri[1] = 0;
	for(int i = 2; i < 1200; i++)
		for(int j = i*2; j < 1200; j+=i)
			pri[j] = 1;
	
	while(gets(s) != NULL) {
		sum = 0;
		for(int i = 0; i < strlen(s); i++)
			if(s[i] >= 'a' && s[i] <= 'z')
				sum += s[i]-'a'+1;
			else if(s[i] >= 'A' && s[i] <= 'Z')
				sum += s[i]-'A'+27;
		
		if(!pri[sum])
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");
	}
	
	return 0;
}

/*
It is a prime word.
It is not a prime word.
*/