#include <stdio.h>
#include <string.h>

int cnt;

int printDiff(int start) {
  int end = start+cnt;
  int x = 1;

  while (start/x != end/x) {
    x*=10;
  }

  printf("-%d", end%x);
  return 0;
}

int printStart(int start) {
  printf("0%d", start);
  if (cnt) {
    printDiff(start);
    cnt = 0;
  }
  printf("\n");
  return 0;
}

int main(void)
{
  int n, c = 1;
  int phone, start;

  while (EOF != scanf("%d", &n) && n) {
    cnt = 0;
    printf("Case %d:\n", c++);

    scanf("%d", &start);
    n--;

    while (n--) {
      scanf("%d", &phone);

      if (phone - start != cnt+1) {
        printStart(start);
        start = phone;
      } else {
        cnt++;
      }

    }
    printStart(start);        
    printf("\n");
  }

  return 0;
}

