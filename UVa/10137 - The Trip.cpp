#include <stdio.h>
#include <math.h>
int main(void)
{
	int n, x, y;
	int num[1005];
	int sum, average, cnt1, cnt2;
	
	while(EOF != scanf("%d", &n) && n) {
		sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d.%d", &x, &y);
			num[i] = 100*x+y;
			sum += num[i];
		}
		
		average = floor((double)sum/n+0.5);
		cnt1 = 0;
		cnt2 = 0;
		for(int i = 0; i < n; i++)
			if(num[i] > average)
				cnt1 += num[i]-average;
			else
				cnt2 += average-num[i];
		printf("$%d.%02d\n", cnt1 > cnt2 ? cnt2/100 : cnt1/100, cnt1 > cnt2 ? cnt2%100 : cnt1%100);
	}

	return 0;
}