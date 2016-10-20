#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int N, M;
	long long ans;
	
	while(EOF != scanf("%d %d", &N, &M) && N && M) {
		
		ans = 1;
		
		for(int i = N, j = 1; i > max(N-M, M); i--, j++) {
			ans *= i;
			ans /= j;
		}
		printf("%d things taken %d at a time is %d exactly.\n", N, M, ans);
	}

	return 0;
}