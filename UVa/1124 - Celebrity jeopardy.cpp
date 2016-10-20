#include <stdio.h>
int main(void)
{
	char a[30];
	while(gets(a) != NULL)
		printf("%s\n", a);
	return 0;
}