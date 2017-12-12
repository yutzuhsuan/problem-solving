#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int weight[105], cost[105];
int c[10220];

int main(void)
{
  int m, n;

  while (EOF != scanf("%d %d", &m, &n)) {
    for (int i = 0; i < n; i++)
      scanf("%d %d", &weight[i], &cost[i]);

    memset(c, 0, sizeof(c));
    if (m > 1800) m += 200;

    for (int i = 0; i < n; i++)
      for (int j = m; j - weight[i] >= 0; j--)
        if (c[j-weight[i]] > 0 || j == weight[i])
          c[j] = max(c[j], c[j-weight[i]]+cost[i]);


    int k = m-200;
    int ans = 0;

    if (k > 1800 && k <= 2000) {
      for (int i = 0; i < k; i++)
        ans = max(ans, c[i]);
      for (int i = 2001; i <= m; i++)
        ans = max(ans, c[i]);
    } else {
      for (int i = 0; i <= m; i++)
        ans = max(ans, c[i]);
    }
    printf("%d\n", ans);
    
  }

  return 0;
}
