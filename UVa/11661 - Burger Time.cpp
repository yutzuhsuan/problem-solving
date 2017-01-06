#include <stdio.h>
int main(void)
{
  int n;
  int r, d, ans;
  char c;

  while (EOF != scanf("%d\n", &n) && n) {
    r = -1, d = -1, ans = 1e9;
    for (int i = 0; i < n; i++) {
      scanf("%c", &c);

      if (c == 'D') {
        if (i - r < ans && r != -1) {
          ans = i - r;
        }
        d = i;
      } else if (c == 'R') {
        if (i - d < ans && d != -1) {
          ans = i - d;
        }
        r = i;
      } else if (c == 'Z') {
        ans = 0;
      }
    }

    printf("%d\n", ans);

  }

  return 0;
}

