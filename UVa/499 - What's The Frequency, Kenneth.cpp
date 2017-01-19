#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[1005];
	int max;
	int upper[26], lower[26];

	while(gets(s) != NULL) {
		
		memset(lower, 0, sizeof(lower));
		memset(upper, 0, sizeof(upper));
		max = 0;
		for(int i = 0; i < strlen(s); i++) {
			if(s[i] >= 'a' && s[i] <= 'z') {
				lower[s[i]-'a']++;
				if(lower[s[i]-'a'] > max)
					max = lower[s[i]-'a'];
			}
			else if(s[i] >= 'A' && s[i] <= 'Z') {
				upper[s[i]-'A']++;
				if(upper[s[i]-'A'] > max)
					max = upper[s[i]-'A'];
			}
		}

		for(int i = 0; i < 26; i++)
			if(upper[i] == max)
				printf("%c", i+'A');
		for(int i = 0; i < 26; i++)
			if(lower[i] == max)
				printf("%c", i+'a');

		printf(" %d\n", max);
	}

	return 0;
}