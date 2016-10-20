#include <stdio.h>
int main(void)
{
	int t, n, kase = 1;
	int a[100];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int tmp, M = 0, J = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			M += (tmp / 30 + 1) * 10;
			J += (tmp / 60 + 1) * 15;
		}
		
		if(M < J)
			printf("Case %d: Mile %d\n", kase++, M);
		else if(J < M)
			printf("Case %d: Juice %d\n", kase++, J);
		else
			printf("Case %d: Mile Juice %d\n", kase++, M);
	}

	return 0;
}