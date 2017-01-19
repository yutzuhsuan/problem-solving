#include <stdio.h>
#include <string.h>
int main(void)
{
	
	char s1[260], s2[260];
	int n1[260], n2[260], ans[550], flag;
	
	while(gets(s1) != NULL) {
		gets(s2);

		memset(n1, 0, sizeof(n1));
		memset(n2, 0, sizeof(n2));
		memset(ans, 0, sizeof(ans));
		
		for(int i = strlen(s1)-1, j = 0; i >= 0; i--, j++)
			n1[j] = s1[i]-'0';
		for(int i = strlen(s2)-1, j = 0; i >= 0; i--, j++)
			n2[j] = s2[i]-'0';
		
		for(int i = 0; i < 255; i++)
			for(int j = 0; j < 255; j++) {
				ans[i+j] += n1[i]*n2[j];
				ans[i+j+1] += ans[i+j]/10;
				ans[i+j] %= 10;
			}
		
		flag = 0;
		for(int i = 510; i >= 0; i--) {
			if(ans[i])
				flag = 1;
			if(flag)
				printf("%d", ans[i]);
		}
		if(!flag)
			printf("0");
		puts("");
	}

	return 0;
}