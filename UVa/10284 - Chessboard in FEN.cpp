#include <stdio.h>
#include <string.h>

int board[8][8];
int position[4][2] = {
  {1, 1},
  {-1, 1},
  {1, -1},
  {-1, -1},
};
int k[8][2] = {
  {1, -1},
  {1, 0},
  {1, 1},
  {0, -1},
  {0, 1},
  {-1, -1},
  {-1, 0},
  {-1, 1},
};
int n[8][2] = {
  {2, 1},
  {1, 2},
  {-1, 2},
  {-2, 1},
  {-2, -1},
  {-1, -2},
  {1, -2},
  {2, -1},
};

bool checkBoundaryAndSet(int x, int y) {
  if (x >= 0 && x < 8 && y >= 0 && y < 8) {
    if (board[x][y] > 1)
      return false;
    else {
      // printf("%d %d %c\n", x, y, board[x][y]);
      board[x][y] = 1;
      return true;
    }
  }
  return false;
}

int findAttack(int x, int y, char p) {
  bool xp, xn, yp, yn;

  if (p == 'q' || p == 'Q' || p == 'r' || p == 'R') {
    xp = true, xn = true, yp = true, yn = true;
    for (int i = 1; i < 8; i++) {
      if (xp) xp = checkBoundaryAndSet(x, y+i);
      if (xn) xn = checkBoundaryAndSet(x, y-i);
      if (yp) yp = checkBoundaryAndSet(x+i, y);
      if (yn) yn = checkBoundaryAndSet(x-i, y);
    }
  }

  if (p == 'b' || p == 'B' || p == 'q' || p == 'Q') {
    xp = true, xn = true, yp = true, yn = true;
    for (int i = 1; i < 8; i++) {
      if (xp) xp = checkBoundaryAndSet(x+position[0][0]*i, y+position[0][1]*i);
      if (xn) xn = checkBoundaryAndSet(x+position[1][0]*i, y+position[1][1]*i);
      if (yp) yp = checkBoundaryAndSet(x+position[2][0]*i, y+position[2][1]*i);
      if (yn) yn = checkBoundaryAndSet(x+position[3][0]*i, y+position[3][1]*i);
    }
  }

  if (p == 'k' || p == 'K')
    for (int i = 0; i < 8; i++)
      checkBoundaryAndSet(x+k[i][0], y+k[i][1]);

  if (p == 'n' || p == 'N')
    for (int i = 0; i < 8; i++)
      checkBoundaryAndSet(x+n[i][0], y+n[i][1]);

  if (p == 'p') {
    checkBoundaryAndSet(x+1, y+1);
    checkBoundaryAndSet(x+1, y-1);
  }

  if (p == 'P') {
    checkBoundaryAndSet(x-1, y+1);
    checkBoundaryAndSet(x-1, y-1);
  }

  return 0;
}

int main(void)
{
  char s[100];

  while (EOF != scanf("%s", s)) {
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        board[i][j] = 0;

    int x = 0, y = 0, sLen;

    sLen = strlen(s);
    for (int i = 0; i < sLen; i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        y += (s[i] - '0');
      } else if (s[i] == '/') {
        x++;
        y = 0;
      } else {
        board[x][y] = s[i];
        y++;
      }
    }

    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        if (board[i][j] > 1)
          findAttack(i, j, board[i][j]);


    int cnt = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++)
        if (!board[i][j]) {
          // printf("0 ");
          cnt++;
        } else {
          // printf("%c ", board[i][j]);
        }
      // puts("");
    }
    // printf("----------------\n");
    printf("%d\n", cnt);
    // puts("");
  }

  return 0;
}

