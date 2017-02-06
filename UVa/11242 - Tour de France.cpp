#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
  int f, r;
  double F[12], R[12];
  double d[105];
  double ans;
  int cnt;

  while (EOF != scanf("%d %d", &f, &r) && f) {
    for (int i = 0; i < f; i++)
      scanf("%lf", &F[i]);
    for (int i = 0; i < r; i++)
      scanf("%lf", &R[i]);

    cnt = 0;
    for (int i = 0; i < f; i++)
      for (int j = 0; j < r; j++)
        d[cnt++] = R[j]/F[i];

    sort(d, d+cnt);

    ans = 0;
    for (int i = 1; i < cnt; i++)
      ans = max(ans, d[i]/d[i-1]);

    printf("%.2lf\n", ans);
  }

  return 0;
}

