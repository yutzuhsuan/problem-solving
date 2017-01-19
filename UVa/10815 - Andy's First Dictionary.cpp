#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m;
int main(void)
{
	char temp[205];
	int cnt = 0;
	char c;
	while(c = getchar()) {
		if(c == EOF)
			break;
		if(c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
		if(c >= 'a' && c <= 'z') {
			temp[cnt++] = c;
		}
		else {
			temp[cnt++] = '\0';
			if(cnt > 1)
				m[temp] = 1;
			cnt = 0;
		}
	}

	for(map<string, int>::iterator i = m.begin(); i != m.end(); i++)
		printf("%s\n", i->first.c_str());

	return 0;
}