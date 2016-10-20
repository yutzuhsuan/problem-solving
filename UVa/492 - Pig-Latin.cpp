#include <stdio.h>
#include <string.h>
char s[1000005];
char vowel[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
int main(void)
{
	int s_len;
	char tmp;
	
	int flag = 0;
	
	while(gets(s) != NULL) {
		s_len = strlen(s);
		for(int i = 0; i < s_len; i++)
			if(!flag) {
				if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
					tmp = s[i];
					for(int j = 0; j < 10; j++)
						if(s[i] == vowel[j]) {
							tmp = -1;
							printf("%c", s[i]);
							break;
						}
					flag = 1;
				}
				else
					printf("%c", s[i]);
			}
			else if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
				printf("%c", s[i]);
			else {
				flag = 0;
				if(tmp != -1)
					printf("%c", tmp);
				printf("ay");
				printf("%c", s[i]);
			}
		if(flag) {
			flag = 0;
			if(tmp != -1)
				printf("%c", tmp);
			printf("ay");
		}
		puts("");
	}

	return 0;
}