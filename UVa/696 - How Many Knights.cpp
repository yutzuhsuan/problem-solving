#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main(void)
{
  int n, m;

  while (EOF != scanf("%d %d", &n, &m) && (n || m)) {

    if (min(n, m) == 1)
      printf("%d", max(n, m));
    else if (min(n, m) == 2) {
      if (max(n, m)%4 == 0)
        printf("%d", max(n, m)/4*4);
      else if (max(n, m)%4 == 1)
        printf("%d", max(n, m)/4*4+2);
      else if (max(n, m)%4)
        printf("%d", max(n, m)/4*4+4);
    } else
      printf("%d", (n*m+2-1)/2);

    printf(" knights may be placed on a %d row %d column board.\n", n, m);
  }

  return 0;
}

