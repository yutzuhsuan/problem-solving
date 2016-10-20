#include <stdio.h>
int num[105];
int buf[105];
void reverse(int x)
{
	for(int i = 0; i <= x; i++)
		buf[i] = num[i];
	for(int i = 0; i <= x; i++)
		num[i] = buf[x-i];
	return ;
}

int main(void)
{
	char trash, maxP, max, flag;
	int cnt;
	while(EOF != scanf("%d", &num[0])) {
		
		cnt= 1;
		while(EOF != scanf("%c", &trash) && trash != '\n')
			scanf("%d", &num[cnt++]);
		
		for(int i = 0; i < cnt; i++) {
			if(i)
				printf(" ");
			printf("%d", num[i]);
		}
		puts("");
		for(int i = cnt-1; i > 0; i--) {
			max = num[i];
			maxP = i;
			for(int j = i; j >= 0; j--)
				if(num[j] > max) {
					max = num[j];
					maxP = j;
				}
			if(i == maxP && i == 1)
				continue;
			reverse(maxP);
			printf("%d ", cnt-maxP);
			reverse(i);
			printf("%d ", cnt-i);
		}
		printf("0\n");
	}
	
	return 0;
}