#include <stdio.h>
int main(void)
{
	long long n, cnt, ans;
	
	while(EOF != scanf("%lld", &n)) {
		cnt = 0;
		ans = 1;
		while(1) {
			cnt = (cnt*10+1)%n;
			if(!cnt) {
				printf("%lld\n", ans);
				break;
			}
			ans++;
		}
	}

	return 0;
}