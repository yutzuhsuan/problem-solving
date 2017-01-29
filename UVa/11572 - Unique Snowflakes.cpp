#include <stdio.h>
#include <map>
using namespace std;

int num[1000005];
int main(void)
{
  int t, n, snow, max, cnt, pre;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    map<int, int> m;
    max = 0;
    cnt = 0;
    pre = 0;

    for (int i = 1; i <= n; i++) {
      scanf("%d", &num[i]);

      if (m[num[i]] > pre) {
        pre = m[num[i]];
      }

      if (i - pre > max) {
        max = i - pre;
      }


      // printf("%d %d %d\n", m[num[i]], max, pre);

      m[num[i]] = i;
    }

    printf("%d\n", max);
  }
  return 0;
}

