#include <stdio.h>
#include <math.h>
int main(void)
{
  int n, A, B, C;
  int x, y, z;
  int end;
  int boundary;

  scanf("%d", &n);
  while (n--) {
    scanf("%d %d %d", &A, &B, &C);

    end = 0;
    boundary = (int)sqrt(C);
    for (int x = -boundary; x <= boundary; x++) {
      for (int y = -boundary; y*y-x*x <= C; y++) {
        z = A-x-y;

        if (x == y || y == z || x == z) continue;
        if (x * y * z != B) continue;
        if (x*x + y*y + z*z != C) continue;

        printf("%d %d %d\n", x, y, z);
        end = 1;
        break;
      }
      if (end) break;
    }

    if (!end)
      printf("No solution.\n");
    

  }
  return 0;
}

