#include <stdio.h>
#include <map>
using namespace std;

int main(void)
{
  int t, n, snow, max;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    map<int, int> m;
    max = 0;
    while (n--) {
      scanf("%d", &snow);
      if (m[snow]) {
        if (m.size() > max)
          max = m.size();
        m.clear();
      } else {
        m[snow] = 1;
      }
    }

    printf("%d\n", max);

  }
  return 0;
}

