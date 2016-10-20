#include <stdio.h>
int main(void)
{
	char c;
	int cnt = 0;
	
	while(EOF != scanf("%c", &c)) {
		
		if(c == '\n' || c == '!') {
			puts("");
			continue;
		}
		
		if(c >= '0' && c <= '9') {
			cnt += c-'0';
			continue;
		}
		
		if(c == 'b') {
			for(int i = 0; i < cnt; i++)
				printf(" ");
			cnt = 0;
		}
		else {
			for(int i = 0; i < cnt; i++)
				printf("%c", c);
			cnt = 0;
		}
	}
	
	return 0;
}