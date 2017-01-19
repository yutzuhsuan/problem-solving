#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	printf("Lumberjacks:\n");
	int n;
	int s[20], sa[20];
	char tmp;

	scanf("%d", &n);
	while(n--) {
		int cur = -1, ordered = -1;
		for(int i = 0; i < 10; i++) {
			scanf("%d", &s[i]);
			sa[i] = s[i];
		}	

		sort(sa, sa+10);

		int flag = 1;
		for(int i = 0; i < 10; i++)
			if(sa[i] != s[i])
				flag = 0;
		if(flag) {
			printf("Ordered\n");
			continue;
		}

		flag = 1;
		for(int i = 0; i < 10; i++)
			if(sa[i] != s[9-i])
				flag = 0;
		if(flag) {
			printf("Ordered\n");
			continue;
		}
			

		printf("Unordered\n");

	}
	return 0;
}
