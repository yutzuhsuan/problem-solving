#include <cstdio>
#include <cstring>
using namespace std;
int main(void)
{
	int t, n;
	int a[105];
	char s[10];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%s", &s);
			
			if(!strcmp(s, "LEFT"))
				a[i] = -1;
			else if(!strcmp(s, "RIGHT"))
				a[i] = 1;
			else {
				char aa[10];
				int pos;
				scanf("%s %d", aa, &pos);
				a[i] = a[pos];
			}
		}
		
		int ans = 0;
		for(int i = 1; i <= n; i++)
				ans += a[i];
		printf("%d\n", ans);
	}

	return 0;
}