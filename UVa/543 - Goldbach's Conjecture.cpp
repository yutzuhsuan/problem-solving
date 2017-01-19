#include <stdio.h>
#include <string.h>
int num[1000005];

int main(void)
{
	int n;
	int ans;
	
	memset(num, 0, sizeof(num));
	
	for(int i = 3; i < 1000000; i += 2) {
		if(num[i])
			continue;
		for(int j = i*2; j <= 1000000; j+=i)
			num[j] = 1;
	}
	
	while(EOF != scanf("%d", &n) && n) {
		ans = 2;
		
		if(!num[ans] && !num[n-ans] && (n-ans)%2)
			printf("%d = %d + %d\n", n, ans, n-ans);
		else {
			ans = 3;
			while(1) {
				if(!num[ans] && !num[n-ans] && (n-ans)%2) {
					printf("%d = %d + %d\n", n, ans, n-ans);
					break;
				}
				ans += 2;
			}
		}
	}
	
	return 0;
}