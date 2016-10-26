#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
  int t, m, n;
  char c;

  scanf("%d\n", &t);

  while (t--) {
    scanf("%c %d %d\n", &c, &m, &n);

    if (m < n)
      swap(m, n);

    if (c == 'Q' || c == 'r') {
      printf("%d\n", n);
    } else if (c == 'K') {
      printf("%d\n", (m+1)/2*(n+1)/2);
    } else if (n == 1) {
      printf("%d\n", m);
    } else if (n == 2) {
      int tmp;
      if (n%4 == 1)
        tmp = 2;
      else if (n%4 == 2)
        tmp = 4;
      printf("%d\n", n/4*4+tmp);
    } else {
      printf("%d\n", (m*n+1)/2);
    }

  }

  return 0;
}
