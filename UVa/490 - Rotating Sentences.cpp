#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[105][105];
	int cnt = 0;
	int max_strlen = 0;

	for(int i = 0; i < 105; i++)
		for(int j = 0; j < 105; j++)
			s[i][j] = ' ';

	while(gets(s[cnt]) != NULL) {
		if(strlen(s[cnt]) > max_strlen)
			max_strlen = strlen(s[cnt]);
		cnt++;
	}

	for(int i = 0; i < max_strlen; i++) {
		for(int j = cnt-1; j >= 0; j--) {
			if(s[j][i] == '\0')
				printf(" ");
			else
				printf("%c", s[j][i]);
		}
		puts("");
	}

	return 0;
}
