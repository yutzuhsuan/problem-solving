#include <stdio.h>
int main(void)
{
	int n, a[1005], kase = 1;
	while(EOF != scanf("%d", &n) && n) {
		int pos = 0, zero = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if(a[i])
				pos++;
			else
				zero++;
		}	
		printf("Case %d: %d\n", kase++, pos-zero);
	}


	return 0;
}
