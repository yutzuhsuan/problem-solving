#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 1000005;

int n, next[N];
char s[N];

void getNext () {
	int p = 0;
	for (int i = 2; i <= n; i++) {
		while (p > 0 && s[p+1] != s[i])
			p = next[p];

		if (s[p+1] == s[i])
			p++;

		next[i] = p;

		//printf("%d\n", next[i]);
		//System("pause");
		if (p) {
			int k = i - next[i];
			if (i%k == 0)
				printf("%d %d\n", i, i/k);
		}
	}
}

int main () {
	int cas = 1;
	while (scanf("%d", &n) == 1 && n) {
		scanf("%s", s+1);
		printf("Test case #%d\n", cas++);
		getNext();
		puts("");
	}
	return 0;
}