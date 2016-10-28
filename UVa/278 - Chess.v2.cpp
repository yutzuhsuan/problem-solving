#include <stdio.h>
#include <algorithm>
using namespace std;
int solve(c, m, n)
{
  if (m < n)
    return solve(c, n, m);

  if (c == 'Q' || c == 'r') {
    return n;
  } else if (c == 'K') {
    return (m+1)/2*(n+1)/2
  } else if (n == 1) {
    return m;
  } else if (n == 2) {
    int tmp;
    if (n%4 == 1)
      tmp = 2;
    else if (n%4 == 2)
      tmp = 4;
    return n/4*4+tmp;
  } else {
    return (m*n+1)/2;
  }
}

int main(void)
{
  int t, m, n;
  char c;

  scanf("%d\n", &t);

  while (t--) {
    scanf("%c %d %d\n", &c, &m, &n);
    printf("%d\n", solve(c, m, n));
  }

  return 0;
}
