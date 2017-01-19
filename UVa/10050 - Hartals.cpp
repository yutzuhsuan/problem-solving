#include <stdio.h>
int main(void)
{
	int	T, N, P, ans;
	int political[105];
	
	scanf("%d", &T);
	
	while(T--) {
		scanf("%d", &N);
		scanf("%d", &P);
		for(int i = 0; i < P; i++)
			scanf("%d", &political[i]);
		
		ans = 0;
		
		for(int i = 0; i < N; i++) {
			if(i%7 == 5 || i%7 == 6)
				continue;
			for(int j = 0; j < P; j++)
				if(!((i+1)%political[j])) {
					ans++;
					break;
				}
		}
		printf("%d\n", ans);
	}

	return 0;
}