#include <stdio.h>
#include <vector>
using namespace std;
int main (void)
{
  int n, m, k, v, tmp;

  while (EOF != scanf("%d %d", &n, &m)) {

    vector<vector<int> > a(1000000, vector<int>());

    for (int i = 1; i <= n; i++) {
      scanf("%d", &tmp);
      a[tmp].push_back(i);
    }

    while (m--) {
      scanf("%d %d\n", &k, &v);

      if (k - 1 < a[v].size())
        printf("%d\n", a[v][k - 1]);
      else
        printf("0\n");
      
    }

  }
  return 0;
}

