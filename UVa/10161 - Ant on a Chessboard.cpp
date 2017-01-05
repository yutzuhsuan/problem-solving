#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main(void)
{
  int n;

  while (EOF != scanf("%d", &n) && n) {
    int sqrtN = (int)ceil(sqrt(n));
    int r = sqrtN*sqrtN - n + 1;
    int l = n - (sqrtN-1)*(sqrtN-1);

    int a1, a2;
    if (r < l) {
      a1 = r;
      a2 = sqrtN;
    } else {
      a1 = l;
      a2 = sqrtN;
    }

    if (sqrtN % 2) {
      if (r < l) {
        printf("%d %d\n", r, sqrtN);
      } else {
        printf("%d %d\n", sqrtN, l);
      }
    } else {
      if (r < l ) {
        printf("%d %d\n", sqrtN, r);
      } else {
        printf("%d %d\n", l, sqrtN);
      }
    }
  }

  return 0;
}

