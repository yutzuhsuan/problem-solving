#include <stdio.h>
int r[100][9];
int tmp[8];
int cnt = 0;
int col[8] = {}, left[15] = {}, right[15] = {};
void init(int x)
{
	if(x == 8) {
		for(int i = 0; i < 8; i++)
			r[cnt][i] = tmp[i];
		cnt++;
		return ;
	}
	
	for(int i = 0; i < 8; i++) {
		int ld = i-x+7;
		int rd = i+x;
		
		if(!col[i] && !left[ld] && !right[rd]) {
			
			col[i] = 1, left[ld] = 1, right[rd] = 1;
			tmp[x] = i;
			init(x+1);
			
			col[i] = 0, left[ld] = 0, right[rd] = 0;
			
		}
		
	}
	
	return ;
}
int main(void)
{
	init(0);
	int T, ans, sum;
	int m[8][8];
	
	scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				scanf("%d", &m[i][j]);
		
		ans = 0;
		for(int i = 0; i < cnt; i++) {
			sum = 0;
			for(int j = 0; j < 8; j++)
				sum += m[j][r[i][j]];
			if(sum > ans)
				ans = sum;
		}
		printf("%5d\n", ans);
	}

	return 0;
}