#include <stdio.h>
int main(void)
{
  int T, n, tmp, Max, ans;

  scanf("%d", &T);

  while (T--) {
    scanf("%d", &n);
    ans = -1e9;
    scanf("%d", &Max);
    for (int i = 1; i < n; i++) {
      scanf("%d", &tmp);
      if (Max - tmp > ans) ans = Max - tmp;
      if (tmp > Max) Max = tmp;
    }
    printf("%d\n", ans);
  }

  return 0;
}

