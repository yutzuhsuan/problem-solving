#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int n, pre, cur;
	int ans[3005], flag;
	while(EOF != scanf("%d", &n)) {
		memset(ans, 0, sizeof(ans));
		ans[1] = 1;
		flag = 0;
		
		for(int i = 0; i < n; i++)
			if(!i)
				scanf("%d", &cur);
			else {
				pre = cur;
				scanf("%d", &cur);
				ans[abs(cur-pre)] = 1;
			}
			
		for(int i = 1; i <= n-1; i++)
			if(!ans[i]) {
				flag = 1;
				break;
			}
		
		if(!flag)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}