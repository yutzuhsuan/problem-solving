#include <stdio.h>
#include <math.h>
int num[10000];
int main(void)
{
	int i, j;
	int n;
	//答案一定是0到八位數的完全平方數
	for(i = 0; i < 10000; i++)
		num[i] = i * i;
	
	
	while(EOF != scanf(" %d", &n)) {
		int n_pow = 1;
		int n_half_pow = 1;
		
		for(i = 0; i < n; i++)
			n_pow *= 10;
		for(i = 0; i < n/2; i++)
			n_half_pow *= 10;
		
		//printf("%d %d\n", n_pow, n_half_pow);
		
		for(i = 0; i < 10000; i++) {
			//檢查有沒有超過10^n
			if(num[i] >= n_pow)
				break;
			
			//依題目暴力測試
			if((num[i] % n_half_pow + num[i] / n_half_pow)*(num[i] % n_half_pow + num[i] / n_half_pow) == num[i]) {
				//print
				//printf("%d\n", num[i]);
				
				for(j = n-1; j >= 0; j--) {
					if(num[i] / (int)pow(10, j) == 0)
						printf("0");
					else {
						printf("%d", num[i]);
						break;
					}
				}
				puts("");
				
			}
		}
		
	}
	return 0;
}






