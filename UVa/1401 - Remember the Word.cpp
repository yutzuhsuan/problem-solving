#include <stdio.h>
#include <string.h>
char s[300005];
struct TrieNode
{
	TrieNode* l[26];
	int n;
	TrieNode()
	{
		memset(l, 0, sizeof(TrieNode*)*26);
		n = 0;
	}
} *root;

void add(char* str)
{
	TrieNode* p = root;
	for(; *str; ++str) {
		if(!p -> l[*str-'a'])
			p -> l[*str-'a'] = new TrieNode();
		p = p -> l[*str-'a'];
	}
	p -> n++;
	return ;
}

int lookup(int start, int end)
{
	//printf(" %d %d\n", start, end);
	TrieNode* p = root;
	for(int i = start; i < end; i++) {
		//printf("%c\n", s[i]);
		if(!p -> l[s[i]-'a'])
			return -1;
		p = p -> l[s[i]-'a'];
	}
	//printf("><%d\n", p -> n);
	if(p -> n > 0)
		return 1;
	else
		return 0;
}

void release(TrieNode* p = root)
{
	for(int i = 0; i < 26; i++)
		if(p -> l[i])
			release(p -> l[i]);
	delete p;
}

int main(void)
{
	char tmp[4005];
	int kase = 1;
	int ans[300005], n;
	char trash;
	int s_len, buf;
	
	while(EOF != scanf(" %s", s)) {
		root = new TrieNode();
		memset(ans, 0, sizeof(ans));
		scanf("%d", &n);
		scanf("%c", &trash);
		for(int i = 0; i < n; i++) {
			scanf("%s", tmp);
			add(tmp);
		}
		s_len = strlen(s);
		for(int i = strlen(s)-1; i >= 0; i--) {
			for(int j = i+1; j <= s_len; j++) {
				//printf("%d %d %d\n", i, j, strlen(s));
				buf = lookup(i, j);
				if(buf < 0)
					break;
				else if(buf == 1) {
					if(j == s_len)
						ans[i]++;
					ans[i] += ans[j];
					ans[i] %= 20071027;
				}
			}
		}
		printf("Case %d: %d\n", kase++, ans[0]);
		release();
	}
	
	return 0;
}