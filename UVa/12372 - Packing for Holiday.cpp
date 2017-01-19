#include <stdio.h>
int main(void)
{
	int n, kase = 1, tmp;
	scanf("%d", &n);
	while(n--) {
		int flag = 1;
		printf("Case %d: ", kase++);
		for(int i = 0; i < 3; i++) {
			scanf("%d", &tmp);
			if(tmp > 20)
				flag = 0;
		}
		if(flag)
			printf("good\n");
		else
			printf("bad\n");
			
	}
}
