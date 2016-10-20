#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

struct url {
	char s[105];
	int v;
	bool operator < (const url &a) const {
		return a.v < v;
	}	

} u[15];
int main(void)
{
	int t, kase = 1;
	scanf("%d", &t);
	
	while(t--) {	
		for(int i = 0; i < 10; i++)
			scanf("%s %d", u[i].s, &u[i].v);
		sort(u, u+10);
		printf("Case #%d:\n", kase++);
		for(int i = 0; i < 10; i++)
			if(u[i].v == u[0].v)
				printf("%s\n", u[i].s);
			else
				break;
	}


	return 0;
}
