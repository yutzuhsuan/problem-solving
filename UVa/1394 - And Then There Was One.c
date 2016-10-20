#include <stdio.h>
int main(void)
{
	int n ,k ,m;
	int ans;
	while(EOF != scanf(" %d %d %d", &n, &k, &m) && n+k+m) {
		int ans = 0;
		int i;
		for(i = 2; i < n; i++)
			ans = (ans + k) % i;
		ans = (ans+m) % n;
		printf("%d\n",ans+1);
	}
	return 0;
}