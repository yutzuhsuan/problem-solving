#include <stdio.h>
int main(void)
{
	int n, f, size, number, environment;
	int sum;
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d", &f);
		sum = 0;
		while(f--) {
			scanf("%d %d %d", &size, &number, &environment);
			sum += size*environment;
		}
		printf("%d\n", sum);
	}

	return 0;
}