#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int T, m, S, v1[50], v2[50], ans;
	int dp[305][305];
	
	scanf("%d", &T);
	
	while(T--) {
		
		scanf("%d %d", &m, &S);
	
		for(int i = 0; i < m; i++)
			scanf("%d %d", &v1[i], &v2[i]);
	
		for(int i = 0; i <= 300; i++)
			for(int j = 0; j <= 300; j++)
				dp[i][j] = 1e9;
		

		dp[0][0] = 0;
		
		for(int i = 0; i < m; i++)
			for(int j = v1[i]; j <= S; j++)
				for(int k = v2[i]; k <= S; k++)
					if(dp[j-v1[i]][k-v2[i]] != 1e9)
						dp[j][k] = min(dp[j][k], dp[j-v1[i]][k-v2[i]]+1);
	
		ans = 1e9;
		for(int i = 0; i <= S; i++)
			for(int j = 0; j <= S; j++)
				if(i*i+j*j == S*S && dp[i][j] < ans && dp[i][j] != 1e9)
					ans = dp[i][j];
		
		if(ans != 1e9)
			printf("%d\n", ans);
		else
			printf("not possible\n");

	}

	return 0;
}