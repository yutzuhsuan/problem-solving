#include <stdio.h>
int main(void)
{
  int a[105];
  int n;

  while (EOF != scanf("%d", &a[0]) && a[0]) {

    for (n = 1; ; n++) {
      scanf("%d", &a[n]);
      if (!a[n])
        break;
    }


    int s = 999999;
    for (int i = 0; i < n; i++)
      if (a[i] < s)
        s = a[i];

    int check;
    for (; s <= 18000; s++) {
      check = 1;

      for (int i = 0; i < n; i++) {
        int tmp;
        tmp = s%(a[i]*2);

        if (tmp >= a[i]-5) {
          s += a[i]*2-tmp-1;
          check = 0; 
          break;
        }
      }

      if (check) {
        break;
      }
    }

    if (check) {
      printf("%02d:%02d:%02d\n", s/3600, s%3600/60, s%60);
    } else {
      printf("Signals fail to synchronise in 5 hours\n");
    }
  }

  return 0;
}

