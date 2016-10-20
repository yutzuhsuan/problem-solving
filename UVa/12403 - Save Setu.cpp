#include <stdio.h>
#include <string.h>
int main(void)
{
	int n, tmp, sum = 0;
	char s[105];
	scanf("%d", &n);

	while(n--) {
		scanf("%s", s);
		if(!strcmp(s, "donate")) {
			scanf("%d", &tmp);
			sum += tmp;
		}	
		else
			printf("%d\n", sum);
	}

}
