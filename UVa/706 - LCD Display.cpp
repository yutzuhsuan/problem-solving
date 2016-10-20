#include <stdio.h>
#include <string.h>
int main(void)
{
	int s;
	char n[13];
	int a[13];
	int cnt;
	int seg[5][10][2];
	memset(seg, 0, sizeof(seg));
	int flag = 0;
	
	seg[0][0][0] = 1;
	seg[1][0][0] = 1;
	seg[1][0][1] = 1;
	seg[3][0][0] = 1;
	seg[3][0][1] = 1;
	seg[4][0][0] = 1;
	
	seg[1][1][1] = 1;
	seg[3][1][1] = 1;
	
	seg[0][2][0] = 1;
	seg[1][2][1] = 1;
	seg[2][2][0] = 1;
	seg[3][2][0] = 1;
	seg[4][2][0] = 1;
	
	seg[0][3][0] = 1;
	seg[1][3][1] = 1;
	seg[2][3][0] = 1;
	seg[3][3][1] = 1;
	seg[4][3][0] = 1;
	
	seg[1][4][0] = 1;
	seg[1][4][1] = 1;
	seg[2][4][0] = 1;
	seg[3][4][1] = 1;
	
	seg[0][5][0] = 1;
	seg[1][5][0] = 1;
	seg[2][5][0] = 1;
	seg[3][5][1] = 1;
	seg[4][5][0] = 1;
	
	seg[0][6][0] = 1;
	seg[1][6][0] = 1;
	seg[2][6][0] = 1;
	seg[3][6][0] = 1;
	seg[3][6][1] = 1;
	seg[4][6][0] = 1;
	
	seg[0][7][0] = 1;
	seg[1][7][1] = 1;
	seg[3][7][1] = 1;
	
	seg[0][8][0] = 1;
	seg[1][8][0] = 1;
	seg[1][8][1] = 1;
	seg[2][8][0] = 1;
	seg[3][8][0] = 1;
	seg[3][8][1] = 1;
	seg[4][8][0] = 1;
	
	
	seg[0][9][0] = 1;
	seg[1][9][0] = 1;
	seg[1][9][1] = 1;
	seg[2][9][0] = 1;
	seg[3][9][1] = 1;
	seg[4][9][0] = 1;
	
	while(EOF != scanf("%d %s", &s, n)) {
		
		if(flag)
			puts("");
		else
			flag = 1;
		
		if(!s)
			break;
		
		cnt = strlen(n);

		for(int i = 0; i < cnt; i++)
			a[i] = n[i]-'0';
		
		
		for(int i = 0; i < 5; i++) {
			if(i == 0 || i == 2 || i == 4) {
				for(int j = 0; j < cnt; j++) {
					if(j)
						printf(" ");
					printf(" ");
					for(int k = 0; k < s; k++)
						if(seg[i][a[j]][0])
							printf("-");
						else
							printf(" ");
					printf(" ");
				}
				puts("");
			}
			else {
				for(int k = 0; k < s; k++) {
					for(int j = 0; j < cnt; j++) {
						if(j)
							printf(" ");
						if(seg[i][a[j]][0])
							printf("|");
						else
							printf(" ");
						for(int l = 0; l < s; l++)
							printf(" ");
						if(seg[i][a[j]][1])
							printf("|");
						else
							printf(" ");
					}
					puts("");
				}
			}
		}
		
	}
	
	return 0;
}