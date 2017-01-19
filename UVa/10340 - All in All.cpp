#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[100000], b[100000];
	int cnt;
	int a_len, b_len;
	
	while(EOF != scanf("%s", a)) {
		
		scanf("%s", b);
		a_len = strlen(a);
		b_len = strlen(b);
		cnt = 0;

		for(int i = 0; i < b_len && cnt < a_len; i++)
			if(a[cnt] == b[i])
				cnt++;
			
		if(cnt == a_len)
			printf("Yes\n");
		else
			printf("No\n");
		
	}	

	return 0;
}