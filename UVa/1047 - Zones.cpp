#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, b;

vector<pair<vector<int>, int> > v;
vector<pair<vector<int>, int> >::iterator it;
vector<int> ans;
vector<int> cur;
int sum;
int maxx;
int tower[25];

void dfs(int size, int index) {
  if (size == b) {
    int tmpSum = sum;
    vector<int> tmp = cur;
    sort(tmp.begin(), tmp.end());
    for (it = v.begin(); it < v.end(); it++) {

      vector<int> inter;
      set_intersection(tmp.begin(), tmp.end(), it->first.begin(), it->first.end(), back_inserter(inter));

      if (inter.size() > 1)
        tmpSum -= (inter.size()-1)*it->second;
    }

    if (tmpSum > maxx) {
      ans = cur;
      maxx = tmpSum;
    }
  }

  for (;index < n; index++) {
    cur.push_back(index);
    sum += tower[index];
    dfs(size+1, index+1);
    cur.pop_back();
    sum -= tower[index];
  }

  return ;
}

int main(void)
{
  int m, t, tmp, customers;
  int cnt = 1;

  while (EOF != scanf("%d %d", &n, &b) && (n || b)) {
    v.clear();
    for (int i = 0; i < n; i++)
      scanf("%d", &tower[i]);

    scanf("%d", &m);
    while (m--) {
      scanf("%d", &t);
      vector<int> vTmp;
      for (int i = 0; i < t; i++) {
        scanf("%d", &tmp);
        vTmp.push_back(tmp-1);
      }
      sort(vTmp.begin(), vTmp.end());
      scanf("%d", &customers);
      v.push_back(pair<vector<int>, int> (vTmp, customers));
    }

    sum = 0, maxx = 0;
    dfs(0, 0);

   	printf("Case Number  %d\n", cnt++);
    printf("Number of Customers: %d\n", maxx);
    printf("Locations recommended:");
    for (int i = 0; i < ans.size(); i++)
      printf(" %d", ans[i]+1);
    puts("");
    puts("");
		
  }
  return 0;
}

