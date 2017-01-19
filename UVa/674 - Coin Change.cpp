#include <stdio.h>
int ans[7500];
int cent[5] = {1, 5, 10, 25, 50};
int main(void)
{
	int n;
	ans[0] = 1;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j + cent[i] <= 7490; j++)
			ans[j+cent[i]] += ans[j];
	
	while(EOF != scanf("%d", &n))
		printf("%d\n", ans[n]);
	
	return 0;
}