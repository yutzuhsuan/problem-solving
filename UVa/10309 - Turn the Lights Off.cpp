#include <stdio.h>
#include <string.h>
using namespace std;

int cnt;
char map[15][15];
char ini[15][15];

void push(int x, int y)
{
	map[x][y] = !map[x][y];
	map[x-1][y] = !map[x-1][y];
    map[x+1][y] = !map[x+1][y];
    map[x][y-1] = !map[x][y-1];
    map[x][y+1] = !map[x][y+1];
    ++cnt;
	
	return ;
}

int main(void)
{
	int n, ans;
	char name[100];
	
	while(gets(name) != NULL) {
		if(!strcmp(name, "end"))
			break;
		
		for(int i = 1; i <= 10; i++) {
			gets(&map[i][1]);
			for(int j = 1; j <= 10; j++)
				if(map[i][j] == '#')
					ini[i][j] = 0;
				else
					ini[i][j] = 1;
		}
		
		ans = 1e9;
		
		for(int k = 0; k < 1024; k++) {
			for(int i = 1; i <= 10; i++)
				for(int j = 1; j <= 10; j++)
					map[i][j] = ini[i][j];
		
			cnt = 0;
			
			for(int i = 0; i < 10; i++)
				if((k&(1 << i)))
					push(1, i+1);
				
			for(int i = 1; i <= 9; i++)
				for(int j = 1; j <= 10; j++)
					if(map[i][j])
						push(i+1, j);
					
			for(int j = 1; j <= 10 && map[10][j] == 0; j++)
				if(j == 10 && ans > cnt)
					ans = cnt;
		}
		printf("%s %d\n", name, ans);
	}

	return 0;
}