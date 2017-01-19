#include <stdio.h>
int main(void)
{
	char c;
	int flag = 0;
	while(EOF != scanf("%c", &c)) {
		if(c == '"' && !flag) {
			printf("``");
			flag = 1;
		}
		else if(c == '"' && flag) {
			printf("''");
			flag = 0;
		}
		else
			printf("%c", c);
	}


	return 0;
}