#include <stdio.h>

int findValue(char c) {
  if (c == 'A' || c == 'T' || c == 'J' || c == 'Q' || c == 'K')
    return 10;
  else if (c == '2') return 2;
  else if (c == '3') return 3;
  else if (c == '4') return 4;
  else if (c == '5') return 5;
  else if (c == '6') return 6;
  else if (c == '7') return 7;
  else if (c == '8') return 8;
  else if (c == '9') return 9;
}

int main(void)
{
  int n;
  char c[52][5];

  scanf("%d\n", &n);
  for (int k = 1; k <= n; k++) {

    for (int i = 0; i < 52; i++) {
      scanf("%s", c[i]);
    }

    int next = 24, x, y = 0;
    for (int i = 0; i < 3; i++) {
      x = findValue(c[next][0]);
      next = next - 1 - (10 - x);
      y += x;
    }

    printf("Case %d: %s\n", k, c[y+24-next-1]);
  }

  return 0;
}

