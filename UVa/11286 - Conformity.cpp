#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
  int n;
  int tmp[5];
  char buf[20];
  string s;
  int ans;
  int max;

  while (EOF != scanf("%d", &n) && n) {
    map<string, int> m;
    map<string, int>::iterator it;
    max = 0;
    ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++){
        scanf("%d", &tmp[j]);
      }
      sort(tmp, tmp+5);
      sprintf(buf, "%d%d%d%d%d", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
      s = buf;
      m[s]++;
      if (m[s] > max) {
        max = m[s];
        ans = max;
      } else if (m[s] == max) {
        ans += m[s];
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}

