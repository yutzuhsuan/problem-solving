#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
  int T, n, w;
  int train[4000];
  scanf("%d", &T);

  while (T--) {
    scanf("%d", &n);

    if (!n) {
      printf("0\n");
      continue;
    }

    vector<int> v;
    for (int i = 0; i < n; i++) {
      scanf("%d", &w);
      train[n-i-1] = train[n+i] = w;
    }

    v.push_back(train[0]);

    for (int i = 1; i < 2*n; i++) {
      if (train[i] > v.back()) {
        v.push_back(train[i]);
      } else {
        *lower_bound(v.begin(), v.end(), train[i]) = train[i];
      }
    }

    printf("%d\n", v.size());
  }

  return 0;
}

