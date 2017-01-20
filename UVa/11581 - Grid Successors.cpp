#include <stdio.h>
int main(void)
{
  int n;
  int grid[20][5][5];
  int finite, isDone, cnt, sum, notZero;
  char tmp;

  scanf("%d", &n);

  while (n--) {
    finite = 0;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        scanf(" %c", &tmp);
        // scanf(" %d", &grid[0][i][j]);
        grid[0][i][j] = tmp-'0';
        if (grid[0][i][j])
          finite = 1;
      }

    if (!finite) {
      printf("-1\n");
      continue;
    }

    /*
    cnt = 1;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        printf("%d ", grid[cnt-1][i][j]);
      }
      puts("");
    }
    continue;
    */

    isDone = 0;
    cnt = 1;
    while (!isDone) {
      notZero = 0;
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
          sum = 0;
          if (i+1 < 3 && grid[cnt-1][i+1][j]) sum++;
          if (j+1 < 3 && grid[cnt-1][i][j+1]) sum++;
          if (i-1 >= 0 && grid[cnt-1][i-1][j]) sum++;
          if (j-1 >= 0 && grid[cnt-1][i][j-1]) sum++;

          // printf("%d %d %d\n", i, j, sum);
          grid[cnt][i][j] = sum%2;
          if (grid[cnt][i][j])
            notZero = 1;
        }

      /*
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
          printf("%d ", grid[cnt][i][j]);
        puts("");
      }
      */

      if (!notZero) {
        printf("%d\n", cnt-1);
        break;
      }


      isDone = 1;
      // printf("%d\n", cnt);
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (grid[cnt][i][j] != grid[0][i][j]) {
            isDone = 0;
            break;
          }
        }
        if (!isDone)
          break;
      }

      if (isDone) {
        printf("%d\n", cnt-1);
        break;
      }
      cnt++;
    }

  }

  return 0;
}

