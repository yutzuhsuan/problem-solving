#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[100];
  int p[15][2], sLen;

  while (gets(s)) {

    if (s[0] == 'G')
      break;
    sLen = strlen(s);

    int x = 0, y = 0, sum = 0;
    for (int i = 0; i < sLen; i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        p[x][y] = s[i] - '0';
        // sum += (s[i] - '0');
        y++;

        if (y == 2) {
          x++;
          y = 0;
        }
      } else if (s[i] == 'X') {
        p[x][0] = 10;
        p[x][1] = 0;
        // sum += 10;
        x++;
      } else if (s[i] == '/') {
        p[x][1] = 10 - p[x][0];
        // sum += (10 - p[x][0]);
        y = 0;
        x++;
      }
    }

    for (int i = 0; i < 10; i++) {
      if (p[i][0] == 10) {
        sum += 10;
        sum += p[i+1][0];

        if (p[i+1][0] == 10)
          sum += p[i+2][0];
        else
          sum += p[i+1][1];

      } else if (p[i][0] + p[i][1] == 10) {
        sum += 10;
        sum += p[i+1][0];
      } else {
        sum += p[i][0] + p[i][1];
      }

    }
    printf("%d\n", sum);


  }

  return 0;
}

