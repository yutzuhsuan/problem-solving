#include <stdio.h>
#include <string.h>

int main(void)
{
	char c[150];
	int s[300];
	int T;
	int c_len;
	int error;
	int cnt;
	char trash;
	scanf("%d", &T);
	scanf("%c", &trash);
	while(T--) {
		gets(c);
		error = 0;
		cnt = 150;
		memset(s, 0, sizeof(s));
		c_len = strlen(c);
		for(int i = 0; i < c_len; i++) {
			
			if(c[i] == '(')
				s[cnt++] = 1;
			else if(c[i] == '[')
				s[cnt++] = 2;
			else if(c[i] == ')' && s[cnt-1] == 1)
				cnt--;
			else if(c[i] == ']' && s[cnt-1] == 2)
				cnt--;
			else
				error = 1;
		}
		
		if(error || cnt != 150)
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}