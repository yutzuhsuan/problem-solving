#include <stdio.h>
#include <math.h>
int main(void)
{
	int a, b, ans;
	
	while(EOF != scanf("%d %d", &a, &b) && (a || b)) {
		
		int flag = 0;
		ans = 0;
		for(int i = 1;; i++) {
			if(i*i > b)
				break;
			if(i*i >= a)
				flag = 1;
			if(flag)
				ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}