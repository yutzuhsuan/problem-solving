#include <stdio.h>
int dollars[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
double ans[60005];
int main(void)
{
	int money1, money2;
	ans[0] = 1;
	for(int i = 0; i < 11; i++)
		for(int j = 0; j+dollars[i] <= 60000; j++)
			ans[j+dollars[i]] += ans[j];
	
	while(EOF != scanf("%d.%d", &money1, &money2) && (money1 || money2))
		printf("%3d.%02d%17.0lf\n", money1, money2, ans[(money1*100+money2)/5]);

	return 0;
}