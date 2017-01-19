#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct word
{
	char c;
	int cnt;
}w[26];

bool cmp(const struct word &a, const struct word &b)
{
	return a.cnt == b.cnt ? a.c < b.c : a.cnt > b.cnt ;
}

int main(void)
{
	int n;
	int s_len;
	char s[105];
	char trash;
	
	scanf("%d", &n);
	
	for(int i = 0; i < 26; i++) {
		w[i].c = 'A'+i;
		w[i].cnt = 0;
	}
	
	scanf("%c", &trash);
	
	while(n--) {
		gets(s);
		
		s_len = strlen(s);
		for(int i = 0; i < s_len; i++)
			if(s[i] >= 'a' && s[i] <= 'z')
				w[s[i]-'a'].cnt++;
			else if(s[i] >= 'A' && s[i] <= 'Z')
				w[s[i]-'A'].cnt++;
	}

	sort(w, w+26, cmp);
	
	for(int i = 0; w[i].cnt != 0; i++)
		printf("%c %d\n", w[i].c, w[i].cnt);
	
	return 0;
}