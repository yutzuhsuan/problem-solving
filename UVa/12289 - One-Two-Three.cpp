#include <stdio.h>
#include <string.h>
int main(void)
{
	int n, cnt;
	char s[10];
	char a[3][10] = {"one", "two", "three"};
	scanf("%d", &n);
	while(n--) {
		scanf("%s", s);
		for(int i = 0; i < 3; i++) {
			cnt = 0;
			for(int j = 0; j < strlen(a[i]); j++)
				if(a[i][j] != s[j])
					cnt++;
			if(cnt <= 1) {
				printf("%d\n", i+1);
				break;
			}
		}
	}
}
