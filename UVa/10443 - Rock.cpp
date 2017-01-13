#include <stdio.h>

int direction[4][2] = {
  {1, 0},
  {0, 1},
  {-1, 0},
  {0, -1},
};

int main(void)
{
  int t, r, c, n;
  char m[105][105];
  char next[105][105];
  scanf("%d", &t);

  while(t--) {
    scanf("%d %d %d\n", &r, &c, &n);

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%c", &m[i][j]);
        next[i][j] = 'Z';
        // printf("%d %d %c\n", r, c, m[i][j]);
      }
      scanf("\n");
    }

    for (int o = 0; o < n; o++) {
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          int change = 0;
          for (int k = 0; k < 4; k++) {
            int newI = i+direction[k][0];
            int newJ = j+direction[k][1];
            if (newI >= 0 && newI <= r && newJ >= 0 && newJ <= c) {
              if (m[i][j] == 'R' && m[newI][newJ] == 'P')
                next[i][j] = 'P', change = 1;
              if (m[i][j] == 'S' && m[newI][newJ] == 'R')
                next[i][j] = 'R', change = 1;
              if (m[i][j] == 'P' && m[newI][newJ] == 'S')
                next[i][j] = 'S', change = 1;
            }
          }
          if (!change) {
            next[i][j] = m[i][j];
          }
        }
      }

      for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
          m[i][j] = next[i][j];

    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++)
        printf("%c", m[i][j]);
      puts("");
    }

    if(t)
      puts("");
  }

  return 0;
}

