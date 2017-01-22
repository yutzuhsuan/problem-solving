#include <stdio.h>
int main(void)
{
  int n;
  int bit;
  int cnt, shift;
  int a, b;

  while (EOF != scanf("%d", &n) && n) {

    cnt = 0;
    shift = 0;
    a = 0, b = 0;

    while (n) {
      bit = n%2;

      if (bit) {
        if (cnt%2)
          b += (1<<shift); 
        else
          a += (1<<shift); 
        cnt++;
      }

      n/=2;
      shift++;
    }

    printf("%d %d\n", a, b);
  }

  return 0;
}

