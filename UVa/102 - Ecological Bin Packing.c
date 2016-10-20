/* 2015/1/19 */
#include <stdio.h>
int main(void)
{
	int  b1, b2, b3, g1, g2, g3, c1, c2, c3;
	int sum;
	char bin1, bin2, bin3;
	int ans;
	
	while(EOF != scanf(" %d %d %d %d %d %d %d %d %d", &b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3)) {
		ans = 1e9;
		sum = b1+b2+b3+g1+g2+g3+c1+c2+c3;
		if((sum - g1 - c2 - b3) <= ans) {
			ans = sum - g1 - c2 - b3;
			bin1 = 'G';
			bin2 = 'C';
			bin3 = 'B';
		}
		if((sum - g1 - c3 - b2) <= ans) {
			ans = sum - g1 - c3 - b2;
			bin1 = 'G';
			bin2 = 'B';
			bin3 = 'C';
		}
		if((sum - c1 - g2 - b3) <= ans) {
			ans = sum - c1 - g2 - b3;
			bin1 = 'C';
			bin2 = 'G';
			bin3 = 'B';
		}
		if((sum - c1 - b2 - g3) <= ans) {
			ans = sum - c1 - b2 - g3;
			bin1 = 'C';
			bin2 = 'B';
			bin3 = 'G';
		}
		if((sum - b1 - g2 - c3) <= ans) {
			ans = sum - b1 - g2 - c3;
			bin1 = 'B';
			bin2 = 'G';
			bin3 = 'C';
		}
		if((sum - b1 - c2 - g3) <= ans) {
			ans = sum - b1 - c2 - g3;
			bin1 = 'B';
			bin2 = 'C';
			bin3 = 'G';
		}
	
		printf("%c%c%c %d\n", bin1, bin2, bin3, ans);
	
	}
	return 0;
}