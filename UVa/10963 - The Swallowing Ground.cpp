#include <stdio.h>
int main(void)
{
	int t, n, a, b;
	scanf("%d", &t);
	for(int j = 0; j < t; j++) {
		scanf("%d", &n);
		int flag = 1, height;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			if(!i) {
				height = a - b;	
			}
			else {
				if((a-b) != height)
					flag = 0;
			}
		}
		if(j)
			puts("");
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
		
		
	}

	return 0;
}
