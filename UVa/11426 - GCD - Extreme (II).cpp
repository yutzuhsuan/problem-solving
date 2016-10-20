#include <stdio.h>
#include <string.h>
long long ans[4000005];
int phi[4000005];
int main(void)
{
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= 4000000; i++)
		phi[i] = i;
	
	for(int i = 2; i <= 4000000; i++) {
		if(phi[i] == i)
			for(int j = i; j <= 4000000; j+=i)
				phi[j] = phi[j]/i*(i-1);
		for(int j = 1; j * i <= 4000000; j++)
			ans[j*i] += j*phi[i];
	}
	for(int i = 1; i <= 4000000; i++)
		ans[i] += ans[i-1];
	
	int n;
	while(EOF != scanf("%d", &n) && n)
		printf("%lld\n", ans[n]);
	
	return 0;
}