#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int main(void)
{
	int n, flag = 0;
	string tmp;
	string a[20];
	map<string, int> name;

	while(EOF != scanf("%d", &n)) {

		if(!flag)
			flag = 1;
		else
			cout << endl;

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			name[a[i]] = 0;
		}

		for(int i = 0; i < n; i++) {
			string give, given;
			int money, cnt;			
			cin >> give >> money >> cnt;

			if(cnt)
				name[give] -= (money - money%cnt);

			for(int j = 0; j < cnt; j++) {
				cin >> tmp;
				name[tmp] += money / cnt;
			}
		}

		for(int i = 0; i < n; i++)
			cout << a[i] << ' ' << name[a[i]] << endl;

	}

	return 0;
}
