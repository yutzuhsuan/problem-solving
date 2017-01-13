#include <stdio.h>
int main(void)
{
  int n, num, isAns;
  int bingo[5][5];
  
  scanf("%d\n", &n);
  while (n--) {

    isAns = 0;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++) {
        if (i == 2 && j ==2) {
          bingo[i][j] = -1;
          continue;
        }
        scanf("%d", &bingo[i][j]);
      }

    /*
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++)
        printf("%d ", bingo[i][j]);
      puts("");
    }
    */

    for (int i = 0; i < 75; i++) {
      scanf("%d", &num);

      for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++)
          if (bingo[j][k] == num)
            bingo[j][k] = -1;

      int isBingo = 0;
      for (int j = 0; j < 5; j++) {
        int row = 0, col = 0;
        for (int k = 0; k < 5; k++) {
          row += bingo[j][k];
          col += bingo[k][j];
        }
        if (row == -5 || col == -5) {
          isBingo = 1;
          break;
        }
      }

      int diagonal1 = 0, diagonal2 = 0;
      for (int j = 0; j < 5; j++) {
        diagonal1 += bingo[j][j];
        diagonal2 += bingo[j][4-j];
      }

      if (diagonal1 == -5 || diagonal2 == -5)
        isBingo = 1;
      

      if (isBingo && !isAns) {
        printf("BINGO after %d numbers announced\n", i+1);
        isAns = 1;
      }

    }

  }

  return 0;
}

