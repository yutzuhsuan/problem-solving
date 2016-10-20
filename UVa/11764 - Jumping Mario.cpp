#include <stdio.h>
int main(void)
{
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		int cur = -1, tmp, a = 0, b = 0;
		while(n--) {
			scanf("%d", &tmp);
			if(cur == -1)
				cur = tmp;
			else if(tmp > cur)
				a++;
			else if(tmp < cur)
				b++;
			cur = tmp;
		}
		printf("Case %d: %d %d\n", i+1, a, b);

	}
	return 0;
}
