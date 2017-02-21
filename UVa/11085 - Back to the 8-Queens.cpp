#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void)
{
  int q[8];
  int p[8];
  int sum, ans;
  int cnt = 1;
  int check;

  while (EOF != scanf("%d", &q[0])) {
    for (int i = 1; i < 8; i++)
      scanf("%d", &q[i]);

    for (int i = 0; i < 8; i++)
      p[i] = i+1;

    ans = 1e9;
    do {
      check = 0;
      for (int i = 0; i < 8 ; i++) {
        for (int j = i+1; j < 8; j++) {
          if (abs(p[i] - p[j]) == abs(i - j)) {
            check = 1;
            break;
          }
        }
        if (check) break;
      }

      if (check) continue;

      sum = 0;
      for (int i = 0; i < 8; i++) {
        if (p[i] != q[i]) sum++;
        if (sum > ans) break;
      }

      if ( sum < ans ) ans = sum;

    } while (next_permutation(p, p+8));

    printf("Case %d: %d\n", cnt++, ans);
  }

  return 0;
}

