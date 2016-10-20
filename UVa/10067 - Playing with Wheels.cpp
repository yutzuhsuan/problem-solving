#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;

queue<int> q;
int f[10][10][10][10];
int n;
int t1, t2, t3, t4;
int flag;
int ans;
int main(void)
{
	int N, n;
	int a, b, c, d;
	int s1, s2, s3, s4;
	int cnt;
	
	scanf(" %d", &N);
	while(N--) {
		
		flag = 0;
		ans = 1e9;
		memset(f, 0, sizeof(f));
		
		
		scanf(" %d %d %d %d", &s1, &s2, &s3, &s4);	
		scanf(" %d %d %d %d", &t1, &t2, &t3, &t4);
			
		scanf(" %d", &n);
		
		for(int i = 0; i < n; i++) {
			scanf(" %d %d %d %d", &a, &b, &c, &d);
			f[a][b][c][d] = -1;
		}
		q.push(s1);
		q.push(s2);
		q.push(s3);
		q.push(s4);
		q.push(0);
		
		while(!q.empty()) {

			a = q.front();
			q.pop();
			b = q.front();
			q.pop();
			c = q.front();
			q.pop();
			d = q.front();
			q.pop();
			//printf(" %d %d %d %d\n", a, b, c, d);
			cnt = q.front();
			q.pop();
			if(a == t1 && b == t2 && c == t3 && d == t4){
				ans = cnt+1;
				flag = 1;
				break;
			}
			if(f[(a+1)%10][b][c][d] == 0) {
				f[(a+1)%10][b][c][d] = 1;
				q.push((a+1)%10);
				q.push(b);
				q.push(c);
				q.push(d);
				q.push(cnt+1);
			}
			if(f[(a+9)%10][b][c][d] == 0) {
				f[(a+9)%10][b][c][d] = 1;
				q.push((a+9)%10);
				q.push(b);
				q.push(c);
				q.push(d);
				q.push(cnt+1);
			}
			if(f[a][(b+1)%10][c][d] == 0) {
				f[a][(b+1)%10][c][d] = 1;
				q.push(a);
				q.push((b+1)%10);
				q.push(c);
				q.push(d);
				q.push(cnt+1);
			}
			if(f[a][(b+9)%10][c][d] == 0) {
				f[a][(b+9)%10][c][d] = 1;
				q.push(a);
				q.push((b+9)%10);
				q.push(c);
				q.push(d);
				q.push(cnt+1);
			}
			if(f[a][b][(c+1)%10][d] == 0) {
				f[a][b][(c+1)%10][d] = 1;
				q.push(a);
				q.push(b);
				q.push((c+1)%10);
				q.push(d);
				q.push(cnt+1);
			}
			if(f[a][b][(c+9)%10][d] == 0) {
				f[a][b][(c+9)%10][d] = 1;
				q.push(a);
				q.push(b);
				q.push((c+9)%10);
				q.push(d);
				q.push(cnt+1);
			}
			if(f[a][b][c][(d+1)%10] == 0) {
				f[a][b][c][(d+1)%10] = 1;
				q.push(a);
				q.push(b);
				q.push(c);
				q.push((d+1)%10);
				q.push(cnt+1);
			}
			if(f[a][b][c][(d+9)%10] == 0) {
				f[a][b][c][(d+9)%10] = 1;
				q.push(a);
				q.push(b);
				q.push(c);
				q.push((d+9)%10);
				q.push(cnt+1);
			}
		
	
		}
		while(!q.empty())
			q.pop();
		
		if(flag)
			printf("%d\n", ans-1);
		else
			printf("-1\n");
		
	}
	return 0;
}