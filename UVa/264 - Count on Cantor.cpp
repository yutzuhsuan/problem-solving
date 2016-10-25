#include <stdio.h>
#include <math.h>
#include <algorithm>
int main(void)
{
  int n;
  while (EOF != scanf("%d", &n)) {

    int a = sqrt(2*n);

    if (a*(a+1) < 2*n) {
      a++;
    }

    int x, y;

    x = a - (a*(a+1)/2 - n);
    y = a + 1 - x;

    int t;
    if (a%2) {
      t = x;
      x = y;
      y = t;
    }

    printf("TERM %d IS %d/%d\n", n, x, y);

  }

  // (1+n)*n / 2

  return 0;
}
