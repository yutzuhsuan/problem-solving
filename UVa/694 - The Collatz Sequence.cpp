#include <stdio.h>
int main(void)
{
	long long A, L;
	int cnt;
	int T = 1;
	
	while(EOF != scanf("%lld %lld", &A, &L) && A > 0 && L > 0) {
		cnt = 1;
		long long tmp = A;
		while(1) {
			if(tmp == 1) {
				printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", T++, A, L, cnt);
				break;
			}

			if(!(tmp%2))
				tmp /= 2;
			else {
				tmp = 3*tmp+1;
				if(tmp > L) {
					printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", T++, A, L, cnt);
					break;
				}
			}
			cnt++;
		}
		
		
	}

	return 0;
}