#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[20];
	int kase = 1;
	while(EOF != scanf("%s", s)) {
		if(!strcmp(s, "#"))
			break;	
		printf("Case %d: ", kase++);
		if(!strcmp(s, "HELLO"))
			printf("ENGLISH");
		else if(!strcmp(s, "HOLA"))
			printf("SPANISH");
		else if(!strcmp(s, "HALLO"))
			printf("GERMAN");
		else if(!strcmp(s, "BONJOUR"))
			printf("FRENCH");
		else if(!strcmp(s, "CIAO"))
			printf("ITALIAN");
		else if(!strcmp(s, "ZDRAVSTVUJTE"))
			printf("RUSSIAN");
		else
			printf("UNKNOWN");

		puts("");


	}
	return 0;
}
