#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	int T, n, ref[12], ans[12];
	char tmp;
	queue <int> q;
	vector <int> v[12];
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		
		for(int i = 0; i <= n; i++) {
			v[i].clear();
			ref[i] = 0;
		}
		
		for(int i = 1; i <= n; i++)
			for(int j = i; j <= n; j++) {
				scanf(" %c", &tmp);
				if(tmp == '+') {
					v[i-1].push_back(j);
					ref[j]++;
				}
				else if(tmp == '-') {
					v[j].push_back(i-1);
					ref[i-1]++;
				}
			}
		
		for(int i = 0; i <= n; i++)
			if(ref[i] == 0)
				q.push(i);
		
		int cnt = -10;
		int bufCnt;
		int buf[15];
		while(!q.empty()) {
			bufCnt = 0;
			while(!q.empty()) {
				buf[bufCnt++] = q.front();
				ans[q.front()] = cnt;			
				q.pop();
			}
			
			for(int i = 0; i < bufCnt; i++)
				for(int j = 0; j < v[buf[i]].size(); j++) {
					ref[v[buf[i]][j]]--;
					if(!ref[v[buf[i]][j]])
						q.push(v[buf[i]][j]);
				}
			
			cnt++;
		}
		for(int i = 1; i <= n; i++) {
			if(i != 1)
				printf(" ");
			printf("%d", ans[i]-ans[0]-(ans[i-1]-ans[0]));
		}
		puts("");
	}
	
	return 0;
}