#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void)
{
  int n;

  while (EOF != scanf("%d", &n) && n) {
    printf("Printing order for %d pages:\n", n);

    int size = (n+3)/4;
    int face = 0;

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < 2; j++) {
        int a = i*2 + j + 1;
        int b = size*4 + 1 - a;
        if (!j)
          swap(a, b);
        if (a > n && b > n)
          continue;

        printf("Sheet %d, %s: ", i+1, j ? "back " : "front");

        if (a > n)
          printf("Blank, ");
        else
          printf("%d, ", a);

        if (b > n)
          printf("Blank\n");
        else
          printf("%d\n", b);

      }
    }
  }

  return 0;
}

