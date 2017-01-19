#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector <int> v[205];
queue <int> q;

int main(void)
{
	int n, l, x, y;
	int c[205];
	
	while(EOF != scanf("%d", &n) && n) {
		
		scanf("%d", &l);
		memset(c, 0, sizeof(c));
		for(int i = 0; i < 205; i++)
			v[i].clear();
		
		while(!q.empty())
			q.pop();
		
		for(int i = 0; i < l; i++) {
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		q.push(0);
		c[0] = 1;
		int flag = 0;
		
		while(!q.empty()) {
			
			int cur = q.front();
			q.pop();
			for(int i = 0; i < v[cur].size(); i++) {
				if(!c[v[cur][i]]) {
					if(c[cur] == 1)
						c[v[cur][i]] = 2;
					else
						c[v[cur][i]] = 1;
					q.push(v[cur][i]);
				}
				else if(c[v[cur][i]] != c[cur])
					continue;
				else if(c[v[cur][i]] == c[cur]) {
					flag = 1;
					break;
				}
			}
			
			if(flag)
				break;
		}

		for(int i = 0; i < n; i++)
			if(!c[i]) {
				flag = 1;
				break;
			}
			
		if(flag)
			printf("NOT BICOLORABLE.\n");
		else
			printf("BICOLORABLE.\n");
		
	}

	return 0;
}