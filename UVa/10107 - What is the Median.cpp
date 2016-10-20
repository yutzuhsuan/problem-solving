#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	int num[10005];
	int cnt = 0;
	
	while(EOF != scanf("%d", &num[cnt++])) {
		
		sort(num, num+cnt);
		if(cnt%2)
			printf("%d\n", num[cnt/2]);
		else
			printf("%d\n", (num[(cnt-1)/2]+num[(cnt-1)/2+1])/2);
		
	}
	
	return 0;
}