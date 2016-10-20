#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[30005];
queue<int> q;
int visited[30005];
int N;
int bfs(int num)
{
	
	int cnt = 1;
	q.push(num);
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
	return cnt;
}

int main(void)
{
	int T, M;
	int from, to;
	int cnt, max;
	scanf("%d", &T);
	
	while(T--) {
		
		
		max = 0;
		for(int i = 0; i < 30005; i++) {
			v[i].clear();
			visited[i] = 0;
		}
		
		scanf("%d %d", &N, &M);
		
		for(int i = 0; i < M; i++) {
			scanf("%d %d", &from, &to);
			if(find(v[from].begin(), v[from].end(), to) == v[from].end())
				v[from].push_back(to);
			if(find(v[to].begin(), v[to].end(), from) == v[to].end())
				v[to].push_back(from);
		}
		
		for(int i = 0; i < N; i++) {
			if(!visited[i]) {
				visited[i] = 1;
				cnt = bfs(i);
			}
			if(cnt > max)
				max = cnt;
		}
		printf("%d", max);
		if(T)
			puts("");
	}

	return 0;
}