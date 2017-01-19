#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[10];
	int kase = 1;

	while(EOF != scanf("%s", s)) {
		if(!strcmp(s, "*"))
			break;

		printf("Case %d: ", kase++);
		if(!strcmp(s, "Hajj"))
			printf("Hajj-e-Akbar\n");
		else	
			printf("Hajj-e-Asghar\n");
	}
	return 0;
}
