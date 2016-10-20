#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100005];
int n[100005];
struct point{
	int ID;
	int val;
};

queue<struct point> q;
void bfs()
{
	struct point P;
	P.ID = 0;
	P.val = 0;
	
	q.push(P);
	/*
	for(int i = 0; i < v[0].size(); i++)
		printf("%d\n", v[0][i]);
	printf("ya");
	*/
	
	while(!q.empty()) {
		struct point cur = q.front();
		q.pop();
		
		for(int i = 0; i < v[cur.ID].size(); i++)
			if(n[v[cur.ID][i]] > cur.val+1) {
				n[v[cur.ID][i]] = cur.val+1;
				struct point tmp;
				tmp.ID = v[cur.ID][i];
				tmp.val = cur.val+1;
				q.push(tmp);
			}
	}
	
	return ;
}

int main(void)
{

	int T, P, D, x, y;
	
	scanf("%d", &T);
	
	while(T--) {
		scanf("%d %d", &P, &D);
		
		for(int i = 0; i < 100000; i++) {
			v[i].clear();
			n[i] = 1e9;
		}
		
		while(D--) {
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		n[0] = 0;
		bfs();
		
		for(int i = 1; i < P; i++)
			if(n[i] != 1e9)
				printf("%d\n", n[i]);
			else
				printf("INF\n");
		if(T)
			puts("");
	}

	return 0;
}