#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	string country[2005];
	char name[75];
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		cin >> country[i];
		gets(name);
		//printf("%s\n", country[i].c_str());
	}

	sort(country, country+n);
	
	for(int i = 0; i < n; i++) {
		printf("%s", country[i].c_str());
		
		int cnt = 0, j;
		for(j = i; country[j] == country[i]; j++)
			cnt++;
		printf(" %d\n", cnt);
		i = j-1;
	}
	
	return 0;
}