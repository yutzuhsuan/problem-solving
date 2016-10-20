#include <stdio.h>
int main(void)
{
	int N, M;
	int b1, b2, tmp, tmp2;
	
	scanf("%d", &N);
	
	while(N--) {
		scanf("%d", &M);
		
		tmp = M;
		b1 = 0;
		while(tmp) {
			b1 += tmp%2;
			tmp /= 2;
		}
		//printf("%d\n", b1);
		b2 = 0;
		
		tmp = M;

		while(tmp) {
			tmp2 = tmp%10;
			tmp /= 10;
			while(tmp2) {
				b2 += tmp2%2;
				tmp2 /= 2;
			}
		}
		
		//printf("%d\n", b2);
		
		printf("%d %d\n", b1, b2);
		
	}
	
	return 0;
}