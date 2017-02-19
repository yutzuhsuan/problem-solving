#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
  int t, n;
  int M[10][10];
  int p[10];
  int sum;
  int ans;

  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%d", &M[i][j]);

    for (int i = 0; i < n; i++)
      p[i] = i;

    ans = 1e9;
    do {
      sum = 0;
      for (int i = 0; i < n; i++) {
        sum += M[i][p[i]];
      }
      if (sum < ans) {
        ans = sum;
      }
    } while (next_permutation(p, p+n));

    printf("%d\n", ans);
  }

  return 0;
}

