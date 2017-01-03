#include <stdio.h>
int main(void)
{
  int n, m, c;
  int devices[22];
  int status[22];
  int operation;
  int cur, max;
  int Sequence = 1;

  while (EOF != scanf("%d %d %d", &n, &m, &c)  && (n || m || c)) {
    cur = 0, max = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &devices[i]);
      status[i] = 0;
    }

    for (int i = 0; i < m; i++) {
      scanf("%d", &operation);
      if (status[operation]) {
        cur -= devices[operation];
        status[operation] = 0;
      } else {
        cur += devices[operation];
        status[operation] = 1;
      }

      if (cur > max)
        max = cur;
    }

    printf("Sequence %d\n", Sequence++);
    if (max > c) {
      printf("Fuse was blown.\n\n");
    } else {
      printf("Fuse was not blown.\n");
      printf("Maximal power consumption was %d amperes.\n\n", max);
    }

  }

  return 0;
}
