/* 看了好久才看懂題目= = */
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[100000];
int sum[100000];
int main(void)
{
  int n, m;

  while (EOF != scanf("%d", &n)) {
    memset(sum, 0, sizeof(sum));
    m = 0;

    int N = (1<<n);

    for (int i = 0; i < N; i++) {
      scanf("%d", &a[i]);
    }

    for (int i = 0; i < N; i++)
      for (int j = 0; j < n; j++) {
        sum[i] += a[i^(1<<j)];
      }

    for (int i = 0; i < N; i++)
      for (int j = 0; j < n; j++)
        m = max(m, sum[i]+sum[i^(1<<j)]);

    printf("%d\n", m);
  }

  return 0;
}

