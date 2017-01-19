#include <stdio.h>
#include <algorithm>
using namespace std;
int check(int bottle, int borrow)
{
	int sum = bottle;
	int tmp;
	
	bottle += borrow;
	while(bottle >= 3) {
		tmp = bottle/3;
		bottle %= 3;
		bottle += tmp;
		sum += tmp;
	}
	
	if(bottle != borrow && borrow)
		return 0;
	else
		return sum;
}
int main(void)
{
	int n, cnt, ans;
	
	while(EOF != scanf("%d", &n))
		printf("%d\n", max(check(n, 0), max(check(n, 1), check(n, 2))));

	return 0;
}