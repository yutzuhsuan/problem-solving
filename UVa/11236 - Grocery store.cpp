#include <stdio.h>
#include <math.h>
int main(void)
{
  int d, p, s;
  for (int a = 0; a+a+a+a <= 2000; a++)
    for (int b = a; a+b+b+b <= 2000; b++)
      for (int c = b; a+b+c+c <= 2000; c++) {
        p = (long long)a*b*c;

        if (p <= 1000000) continue;

        s = (a+b+c);

        if (s*1000000 % (p - 1000000)) continue;

        d = s*1000000 / (p - 1000000);

        if (a+b+c+d > 2000 || d < c) continue;
        
        printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
      }

  return 0;
}

