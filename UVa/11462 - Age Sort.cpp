#include <stdio.h>
#include <algorithm>
using namespace std;
int num[2000005];
int main(void)
{
	int n;
	
	while(scanf("%d", &n) != EOF && n) {
		for(int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		sort(num, num+n);
		for(int i = 0; i < n; i++) {
			if(i)
				printf(" ");
			printf("%d", num[i]);
		}
		puts("");
	}

	return 0;
}