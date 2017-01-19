#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int LCS[1005][1005];

int main(void)
{
	
	char s1[1005], s2[1005];
	
	while(gets(s1) != NULL) {
		gets(s2);
		
		memset(LCS, 0, sizeof(LCS));
		
		for(int i = 1; i <= strlen(s1); i++)
			for(int j = 1; j <= strlen(s2); j++) {
				if(s1[i-1] == s2[j-1])
					LCS[i][j] = LCS[i-1][j-1] + 1;
				else
					LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
			}

		printf("%d\n", LCS[strlen(s1)][strlen(s2)]);
	}

	return 0;
}