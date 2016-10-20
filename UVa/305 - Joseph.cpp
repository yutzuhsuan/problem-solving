#include <stdio.h>
int main(void)
{
	int x;
	int cnt;
	int pre, cur;
	int flag;
	int ans[14];
	int i;
	for(int k = 1; k < 14; k++) {
		cnt = k+1;
		flag = 0;
		while(!flag) {
			if((cnt-1) % (2*k) >= k && (cnt-1) % (2*k) < 2*k) {
				pre = (cnt-1) % (2*k);
				for(i = 2; i <= k; i++) {
					cur = (pre+cnt-1) % (2*k-i+1);
					if(cur < k || cur >= 2*k)
						break;
					else
						pre = cur;
				}
				if(i == k+1) {
					ans[k] = cnt;
					flag = 1;
				}
			}			
			cnt++;
		}

	}
	
	while(scanf("%d", &x) != EOF && x) {
		/*
		cnt = k+1;
		flag = 0;
		while(!flag) {
			if((cnt-1) % (2*k) >= k && (cnt-1) % (2*k) < 2*k) {
				pre = (cnt-1) % (2*k);
				for(int i = 2; i <= k; i++) {
					cur = (pre+cnt-1) % (2*k-i+1);
					if(cur < k || cur >= 2*k)
						break;
					else
						pre = cur;
					
					if(i == k) {
						ans = cnt;
						flag = 1;
					}
				}
			}			
			cnt++;
		}
		*/
		printf("%d\n", ans[x]);
	}
	
	return 0;
}