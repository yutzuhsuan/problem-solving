#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
  int n, m, r, tmp, p;

  while (EOF != scanf("%d %d", &n, &m)) {
    vector<pair<int, int> > v[10005];
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &r);
      for (int j = 0; j < r; j++) {
        scanf("%d", &tmp);
        q.push(tmp); 
      }
      for (int j = 0; j < r; j++) {
        tmp = q.front();
        q.pop();
        scanf("%d", &p);
        v[tmp].push_back(pair<int, int> (i, p));
      }
    }

    printf("%d %d\n", m, n);
    for (int i = 1; i <= m; i++) {
      printf("%d", v[i].size());
      for (int j = 0; j < v[i].size(); j++) {
        printf(" %d", v[i][j].first);
      }
      puts("");
      for (int j = 0; j < v[i].size(); j++) {
        if (j) printf(" ");
        printf("%d", v[i][j].second);
      }
      puts("");
    }

  }

  return 0;
}

