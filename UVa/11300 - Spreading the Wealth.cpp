#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1000000+10;
long long A[maxn], C[maxn], sum, M;
int main(void)
{
	int n;
	
	while(EOF != scanf("%d", &n)) {
		sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			sum += A[i];
		}
	
		M = sum/n;
		
		C[0] = 0;
		for(int i = 1; i < n; i++)
			C[i] = C[i-1]+A[i]-M;
		sort(C, C+n);
		
		long long x1 = C[n/2], ans = 0;
		
		for(int i = 0; i < n; i++)
			ans += abs(x1-C[i]);
		
		printf("%lld\n", ans);
	
	}

	return 0;
}