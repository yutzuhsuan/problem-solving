/*
 * UVa 108 Maximum Sum                                 
 * Version: 2015/02/10
 * 想法: 技巧性的枚舉 
 */
#include <stdio.h>
#include <algorithm>
using namespace std;
int num[1005];
int main(void)
{
	int n;
	double d_minus_c;
	int i, j, k, l;
	int flag;

	while(EOF != scanf(" %d", &n) && n) {
		flag = 0;
		
		for(i = 0; i < n; i++) 
			scanf(" %d", &num[i]);
		sort(num, num+n);
		
		/*枚舉答案，從最大的開始*/
		for(i = n-1; i >= 0; i--) {
			for(j = n-1; j > 1; j--) {
				/*答案不可能一樣*/
				if(i == j)
					continue;
				/*枚舉d-c*/
				d_minus_c = num[i] - num[j];
				/*另外兩個答案一定比j小，暴力找*/
				for(k = 0, l = j-1;;) {
					if(num[k] + num[l] == d_minus_c) {
						flag = 1;
						break;
					}
					else if(num[k] + num[l] < d_minus_c)
						k++;
					else
						l--;
					
					if(k >= l)
						break;
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		
		if(flag)
			printf("%d\n", num[i]);
		else
			printf("no solution\n");
		
	}
	return 0;
}