#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(void)
{
	char s[55];
	int ans;
	
	while(gets(s) != NULL) {
		if(s[0] == '#')
			break;
		ans = 0;
		for(int i = strlen(s)-1; i > 0; i--)
			if(s[i] > s[i-1]) {
				int exchange;
				char tmp;
				for(int j = strlen(s)-1; j >= i-1; j--)
					if(s[j] > s[i-1]) {
						exchange = j;
						tmp = s[j];
						break;
					}
				for(int j = exchange; j >= i-1; j--)
					s[j] = s[j-1];
				s[i-1] = tmp;
				sort(s+i, s+strlen(s));
				printf("%s\n", s);
				ans = 1;
				break;
			}

		if(!ans)
			printf("No Successor\n");
		
	}

	return 0;
}