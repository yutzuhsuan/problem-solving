#include <stdio.h>
int main(void)
{
	char c;
	while(EOF != scanf("%c", &c)) {
		if(c != '\n')
			printf("%c", c-7);
		else
			puts("");
	}
	return 0;
}