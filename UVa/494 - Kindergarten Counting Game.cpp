#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[20000];
	int cnt, flag;
	
	while(gets(a)) {
		cnt = 0;
		flag = 0;
		for(int i = 0; i < strlen(a); i++)
			if(!flag && ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))) {
				cnt++;
				flag = 1;
			}
			else if(!((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')))
				flag = 0;
		printf("%d\n", cnt);
	}

	return 0;
}