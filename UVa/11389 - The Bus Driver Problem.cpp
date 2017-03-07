#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
  int n, d, r;
  int m[105], e[105];

  while (EOF != scanf("%d %d %d", &n, &d, &r) && (n || d || r)) {
    for (int i = 0; i < n; i++)
      scanf("%d", &m[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &e[i]);
    sort(m, m+n);
    sort(e, e+n);

    int sum = 0;
    for (int i = 0; i < n; i++)
      if (m[i] + e[n-1-i] > d)
        sum += m[i] + e[n-1-i] - d;

    printf("%d\n", sum*r);
  }

  return 0;
}

