#include <stdio.h>
#include <string.h>
int main(void)
{
	int soundex[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};
	char s[30];

	while(gets(s) != NULL) {
		int pre = -1;
		int s_len = strlen(s);
		for(int i = 0; i < s_len; i++) 
			if(soundex[s[i]-'A'] && soundex[s[i]-'A'] != pre) {
				printf("%d", soundex[s[i]-'A']);
				pre = soundex[s[i]-'A'];
			}
			else if(!soundex[s[i]-'A'])
				pre = -1;
		puts("");


	}
	return 0;
}
