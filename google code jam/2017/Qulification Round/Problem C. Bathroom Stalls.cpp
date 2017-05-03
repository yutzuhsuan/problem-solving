#include <stdio.h>
#include <map>
using namespace std;
int main(void)
{
  int T;
  long long N, K;
  long long max, min;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%lld %lld", &N, &K);
    map<long long, long long> M;
    M[N] = 1;

    while (K) {
      pair<long long, long long> e = *M.rbegin();
      // printf("%lld\n", e.first);
      // printf("%lld %lld\n", e.first, e.second);
      M.erase(e.first);

      if (e.second >= K) {
        max = e.first/2;
        min = (e.first-1)/2;
        break;
      }
      // printf("%lld\n", K);
      K -= e.second;

      long long tmp = e.first/2;
      if (e.first%2) {
        M[tmp] += 2LL * e.second;
      } else {
        M[tmp] += e.second;
        M[tmp-1] += e.second;
      }
    }

    printf("Case #%d: %lld %lld\n", t, max, min);
  }

  return 0;
}

