#include <stdio.h>
#include <string.h>
int main(void)
{
	int pri[1005];
	int N, C;
	
	memset(pri, 0, sizeof(pri));
	
	for(int i = 2; i <= 1000; i++) {
		if(pri[i])
			continue;
		for(int j = i*2; j <= 1000; j+=i)
			pri[j] = 1;
	}

	while(EOF != scanf("%d %d", &N, &C)) {
		
		printf("%d %d:", N, C);
		
		int cnt = 0;
		for(int i = 1; i <= N; i++)
			if(!pri[i])
				cnt++;
		
		int start, end;
		if(cnt%2) {
			start = cnt/2-C+2;
			if(start < 1)
				start = 1;
			end = cnt/2+C;
			if(end > cnt)
				end = cnt;
		}
		else {
			start = cnt/2-C+1;
			if(start < 1)
				start = 1;
			end = cnt/2+C;
			if(end > cnt)
				end = cnt;
		}
	
		cnt = 0;
		for(int i = 1; i <= N; i++)
			if(!pri[i]) {
				cnt++;
				if(cnt >= start && cnt <= end)
					printf(" %d", i);		
			}
		
		printf("\n\n");
	}
	
	return 0;
}