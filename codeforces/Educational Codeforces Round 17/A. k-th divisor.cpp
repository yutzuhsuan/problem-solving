#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int main(void)
{
  long long n, k, cnt;
  int end;

  while (EOF != scanf("%I64d %I64d", &n, &k)) {
    cnt = 0, end = 0;


    vector<long long> v;
    for (long long i = 1; i <= (long long)sqrt(n); i++) {
      if (!(n%i)) {
        v.push_back(i);
        cnt++;
      }

      if (cnt == k) {
        end = 1;
        printf("%d\n", i);
        break;
      }
    }

    if (end)
      continue;


    long long target = cnt*2;
    if ((long long)sqrt(n) * (long long)sqrt(n) == n)
      target--;

    if (target < k)
      printf("-1\n");
    else
      printf("%I64d\n", n/v[target-k]);
  }

  return 0;
}

