#include <stdio.h> 
#include <list>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int size;
vector<vector<pair<int, int> > > l;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first < b.first;
}

int query(int L, int R, int v) {
  int lp = L/size;
  int rp = R/size;
  int sum = 0;

  vector<pair<int, int> >::iterator it;
  for (int i = lp; i <= rp; i++) { // iterate through blocks
    if (i == lp || i == rp) { // 某塊有涵蓋 L 或者 R 的話要把整塊都找過 O(sqrt(N))
      for (int j = 0; j < l[i].size(); j++) {
        if (l[i][j].first < v && l[i][j].second >= L && l[i][j].second <= R) {
          sum++;
        }
      }
    } else { // 已經 sort 好了直接 binary search 就可以了 O(log(sqrt(N)))
      // binary search 乖乖自己寫
      int left = 0, right = l[i].size()-1, middle;
      while (left < right) {
        middle = (left+right+1) / 2;
        if (l[i][middle].first < v) left = middle;
        else right = middle-1;
      }
      if (l[i][left].first >= v) left--;
      sum += left+1;
    }
  }
  return sum;
}

int main(void)
{
  int n, m, u, num, k;
  int L, R, v, p;


  while (EOF != scanf("%d %d %d", &n, &m, &u)) {

    size = (int)sqrt(n);
    vector<pair<int, int> > block;
    vector<int> ans;
    for (int i = 0, j = 1; i < n; i++) {
      scanf("%d", &num);
      ans.push_back(num);
      block.push_back(pair<int, int> (num, i));

      if (j == size || i == n-1) {
        sort(block.begin(), block.end(), cmp);
        l.push_back(block);
        block.clear();
        j = 1;
      } else {
        j++;
      }
    }

    vector<pair<int, int> >::iterator it;
    while (m--) {
      scanf("%d %d %d %d", &L, &R, &v, &p);
      L--, R--, p--;
      k = query(L, R, v);
      for (it = l[p/size].begin(); it != l[p/size].end(); it++) {
        if (it->second == p) {
          ans[p] = (int)((long long)u*k/(R-L+1));
          it->first = ans[p];
          break;
        }
      }
      sort(l[p/size].begin(), l[p/size].end(), cmp);
    }

    for (int i = 0; i < ans.size(); i++)
      printf("%d\n", ans[i]);

  }

  return 0;
}

