#include <stdio.h>
int main(void)
{
  int N, n, cnt;
  char tmp;
  char big[105][105], small[4][105][105];

  while (EOF != scanf("%d %d\n", &N, &n) && N && n) {

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf(" %c", &big[i][j]);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf(" %c", &tmp);
        small[0][i][j] = tmp;
        small[1][j][n-1-i] = tmp;
        small[2][n-1-i][n-1-j] = tmp;
        small[3][n-1-j][i] = tmp;
      }
    }

    /*
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++)
          printf("%c ", small[i][j][k]);
        puts("");
      }
    */

    int check;

    for (int i = 0; i < 4; i++) {
      
      cnt = 0;
      for (int j = 0; j <= N-n; j++) {
        for (int k = 0; k <= N-n; k++) {
          check = 1;
          for (int l = 0; l < n; l++) {
            for (int m = 0; m < n; m++) {
              if (big[j+l][k+m] != small[i][l][m]) {
                check = 0;
                break;
              }
            }
            if (!check)
              break;
          }
          if (check)
            cnt++;
        }
      }

      if (i) printf(" ");
      printf("%d", cnt); 
    }
    puts("");

  }

  return 0;
}

