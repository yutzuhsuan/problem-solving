#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int t, n;
int x[12];
vector<int> v;
vector<int>::iterator it;
map<string, int> m;
void dfs(int sum, int i) {
  if (sum > t) return ;
  if (sum == t) {
    string tmp;
    for (it = v.begin(); it != v.end(); it++) {
      if (it != v.begin()) tmp += "+";
      tmp += to_string(*it);
    }
    if (!m[tmp]) {
      cout << tmp << endl;
      m[tmp] = 1;
    }
  }

  for (; i < n; i++) {
    v.push_back(x[i]);
    dfs(sum + x[i], i+1);
    v.pop_back();
  }
}

int main(void)
{

  while (EOF != scanf("%d %d", &t, &n) && (t || n)) {
    v.clear();
    m.clear();

    for (int i = 0; i < n; i++)
      scanf("%d", &x[i]);

    printf("Sums of %d:\n", t);
    dfs(0, 0);

    if (!m.size())
      printf("NONE\n");
  }

  return 0;
}

