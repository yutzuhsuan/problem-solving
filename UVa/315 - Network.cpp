#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> v[105];
queue<int> q;
int visited[105];

bool bfs() {
	
	int cnt = 1;
	
	for(int i = 1; i <= N; i++)
		if(!visited[i]) {
			visited[i] = 1;
			q.push(i);
			//printf("%d\n", i);
			break;
		}
	
	while(!q.empty()) {
		for(vector<int>::iterator i = v[q.front()].begin(); i != v[q.front()].end(); i++) {
			if(!visited[*i]) {
				visited[*i] = 1;
				q.push(*i);
				cnt++;
			}
		}
		q.pop();
	}
	
	//printf("%d\n", cnt);
	
	if(cnt == N-1)
		return false;
	else
		return true;
}

int main(void)
{
	char trash;
	int from, to;
	int ans;
	
	while(EOF != scanf("%d", &N) && N) {
		
		ans = 0;
		
		for(int i = 0; i < 105; i++) {
			v[i].clear();
			visited[i] = 0;
		}
		
		while(scanf("%d", &from) && from) {
			while(1) {
				scanf("%c", &trash);
				if(trash == '\n')
					break;
				scanf("%d", &to);
				v[from].push_back(to);
				v[to].push_back(from);
			
			}
		}
		
		for(int i = 1; i <= N; i++) {
			//printf("----%d----\n", i);
			visited[i] = 1;
			if(bfs())
				ans++;
			for(int j = 0; j <= N; j++)
				visited[j] = 0;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}