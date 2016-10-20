#include <stdio.h>
int a[25];
int min, max, tmp;
int main(void)
{
	int t, n;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		max = 0;
		min = 1e9;
		while(n--) {
			scanf("%d", &tmp);
			if(tmp > max)
				max = tmp;
			if(tmp < min)
				min = tmp;
		}

		printf("%d\n", (max-min)*2);

	}

	return 0;
}
