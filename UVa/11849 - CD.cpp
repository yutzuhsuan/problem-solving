#include <stdio.h>
#include <map>
using namespace std;
int main(void)
{
  int n, m, k;
  int ans;

  while (EOF != scanf("%d %d", &n, &m) && (n || m)) {
    map<int, int> cd;
    ans = 0;
    while (n--) {
      scanf("%d", &k);
      cd[k] = 1;
    }
    
    while (m--) {
      scanf("%d", &k);
      if (cd[k])
        ans++;
    }
    printf("%d\n", ans);

  }

  return 0;
}

