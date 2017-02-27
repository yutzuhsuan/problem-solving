#include <stdio.h>
int main(void)
{
  int n, m; 
  int c[1000005];
  int l, r, mid;
  int tmp, cnt;
  int ans;

  while (EOF != scanf("%d %d", &n, &m)) {
    l = 0;
    r = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &c[i]);
      r += c[i];
      if (c[i] > l) l = c[i]-1;
    }

    ans = r;
    while (l < r-1) {
      mid = (l+r)/2;
      tmp = 0;
      cnt = 1;
      for (int i = 0; i < n; i++) {
        if (tmp + c[i] <= mid) {
          tmp += c[i];
        } else if (c[i] <= mid) {
          cnt++;
          tmp = c[i];
        }
      }

      if (cnt > m) {
        l = mid;
      } else {
        r = mid;
        ans = mid;
      }


    }
    printf("%d\n", ans);
  }

  return 0;
}

