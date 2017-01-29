#include <stdio.h>
#include <set>
using namespace std;

int main(void)
{
  int n, m, k;
  long long sum;

  while (EOF != scanf("%d", &n) && n) {
    sum = 0;
    multiset<int> s;

    while (n--) {
      scanf("%d", &m);
      while (m--) {
        scanf("%d", &k);
        s.insert(k);
      }
      
      sum += *(--s.end()) - *s.begin();
      s.erase(s.begin());
      s.erase(--s.end());
    }
    printf("%lld\n", sum);
  }

  return 0;
}

