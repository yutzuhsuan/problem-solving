#include <stdio.h>
#include <string.h>
int main(void)
{
	int s, h, e, cur;
	int city[10005];
	
	memset(city, 0, sizeof(city));
	while(EOF != scanf("%d %d %d", &s, &h, &e)) {
		for(int i = s; i < e; i++)
			if(city[i] <= h)
				city[i] = h;	
	}

	cur = 0;
	int flag = 0;
	for(int i = 1; i <= 10000; i++) {
		if(city[i] != cur) {
			if(flag)
				printf(" ");
			else
				flag = 1;
			printf("%d %d", i, city[i]);
			cur = city[i];
		}
	}
	puts("");
	return 0;
}