#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

map<long long int, int> record;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

void init()
{
	int init_board[5][5] = {
        {1,1,1,1,1},
        {2,1,1,1,1},
        {2,2,0,1,1},
        {2,2,2,2,1},
        {2,2,2,2,2}
    };
	int board[5][5];
	long long int tmp = 0;
	long long int init_state;
	int tx, ty, ox, oy;
	
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			tmp = tmp*3 + init_board[i][j];
	
	
	init_state = tmp;
	queue<long long int> q;
	
	record[tmp] = 0;
	q.push(tmp);
	long long int cur;
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		
		int step = record[cur];
		if(step == 10)
			continue;
		
		tmp = cur;
		for(int i = 4; i >= 0; i--)
			for(int j = 4; j >= 0; j--) {
				board[i][j] = tmp%3;
				tmp /= 3;
				if(!board[i][j]) {
					ox = i;
					oy = j;
				}
			}
		
		for(int k = 0; k < 8; k++) {
			tx = ox+dx[k];
			ty = oy+dy[k];
			
			if(tx < 0 || ty < 0 || tx > 4 || ty > 4)
				continue;
			
			swap(board[tx][ty], board[ox][oy]);
			
			tmp = 0;
			
			for(int i = 0; i < 5; i++)
				for(int j = 0; j < 5; j++)
					tmp = tmp*3+board[i][j];
				
			if(record[tmp] == 0 && tmp != init_state) {
				record[tmp] = step+1;
				q.push(tmp);
			}
			swap(board[tx][ty], board[ox][oy]);
		}
	}
	
	return ;
}

int main(void)
{
	init();
	long long cur;
	char trash;
	char m[10][10];
	int T;

	scanf("%d", &T);
	scanf("%c", &trash);
	
	while(T--) {
		cur = 0;
		for(int i = 0; i < 5; i++)
			gets(m[i]);
		
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 5; j++)
				if(m[i][j] == '1')
					cur = cur*3+1;
				else if(m[i][j] == '0')
					cur = cur*3+2;
				else
					cur *= 3;
		if(record.find(cur) == record.end())
			printf("Unsolvable in less than 11 move(s).\n");
		else
			printf("Solvable in %d move(s).\n", record[cur]);
	}
	
	return 0;
}