#include <stdio.h>
#include <string.h>
int main(void)
{
	int n, s_len;
	char s[1000];
	scanf("%d", &n);
	while(n--) {
		scanf("%s", s);
		s_len = strlen(s);

		if(!strcmp(s, "1"))
			printf("+");
		else if(!strcmp(s, "4"))
			printf("+");
		else if(!strcmp(s, "78"))
			printf("+");
		else if(s[s_len-1] == '5' && s[s_len-2] == '3')
			printf("-");
		else if(s[0] == '9' && s[s_len-1] == '4')
			printf("*");
		else if(s[0] == '1' && s[1] == '9' && s[2] == '0')
			printf("?");
		puts("");
	}

	return 0;
}
