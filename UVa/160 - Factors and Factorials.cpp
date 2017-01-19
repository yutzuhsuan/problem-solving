#include <stdio.h>
#include <string.h>
int main(void)
{
	int n;
	int pri[30];
	int pri_cnt = 0;
	int tmp[105] = {};
	int cur, cnt;
	int max_cnt;
	int ans[30];
	
	for(int i = 2; i <= 100; i++) {
		if(tmp[i])
			continue;
		else
			pri[pri_cnt++] = i;
		for(int j = i*2; j <= 100; j+=i)
			tmp[j] = 1;
	}
	
	
	while(EOF != scanf("%d", &n) && n) {
		
		memset(ans, 0, sizeof(ans));
		max_cnt = 0;
		for(int i = 2; i <= n; i++) {
			cur = i;
			cnt = 0;
			while(cur != 1) {
				//printf("%d\n", cur);
				while(!(cur%pri[cnt])) {
					cur /= pri[cnt];
					ans[cnt]++;
					if(cnt > max_cnt)
						max_cnt = cnt;
				}
				cnt++;			
			}
		}
		printf("%3d! =", n);
		for(int i = 0; i <= max_cnt; i++) {
			if(!(i%15) && i)
				printf("\n      ");
			printf(" %2d", ans[i]);
		}
		puts("");
	}

	return 0;
}