#include <stdio.h>
int main(void)
{
	
	char c;
	int cnt = 0;
	char word[20];
	
	while(EOF != scanf("%c", &c)) {
		
		if(c == ' ' || c == '\n') {
			
			for(int i = cnt-1; i >= 0; i--)
				printf("%c", word[i]);
			cnt = 0;
			
			if(c == ' ')
				printf(" ");
			else if(c == '\n')
				puts("");
		}
		else
			word[cnt++] = c;
	
	
	}

	return 0;
}