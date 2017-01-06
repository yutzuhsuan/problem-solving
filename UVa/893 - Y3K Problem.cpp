#include <stdio.h>
int month[13] = {
  0, 
  31,
  28,
  31,
  30,
  31,
  30,
  31,
  31,
  30,
  31,
  30,
  31,
};

int main(void)
{
  int n, d, m, y;

  while (EOF != scanf("%d %d %d %d", &n, &d, &m, &y) && (n || d || m || y)) {
    n += d;
    while (n > month[m]) {

      if (y%400 == 0 || (y%4 == 0 && y%100 != 0)) {
        month[2] = 29;
      } else {
        month[2] = 28;
      }

      n -= month[m++];

      if (m == 13) {
        y++;
        m = 1;
      }
    }

    printf("%d %d %d\n", n, m, y);

  }

  return 0;
}

