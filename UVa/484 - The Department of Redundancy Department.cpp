#include <stdio.h>
#include <string.h>
int main(void)
{
	int tmp, i, max = 0;
	int num[10005];
	int cnt[10005];
	
	memset(num, 0, sizeof(num));
	memset(cnt, 0, sizeof(cnt));
	
	while(EOF != scanf("%d", &tmp)) {
		
		for(i = 0; i < max; i++)
			if(num[i] == tmp) {
				cnt[i]++;
				break;
			}

		if(i == max) {
			num[max] = tmp;
			cnt[max] = 1;
			max++;
		}
	}
	for(i = 0; i < max; i++)
		printf("%d %d\n", num[i], cnt[i]);

	return 0;
}