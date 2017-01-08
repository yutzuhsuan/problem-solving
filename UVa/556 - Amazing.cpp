#include <stdio.h>
#define max 105

int direction[4][2] = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0},
};

int main(void)
{
  int b, w, d;
  int curB, curW;
  int maze[max][max];

  char c;

  while (EOF != scanf("%d %d\n", &b, &w) && (b || w)) {

    for (int i = 0; i < max; i++)
      for (int j = 0; j < max; j++)
        maze[i][j] = -1;
    
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= w; j++) {
        scanf("%c", &c);
        if (c == '0')
          maze[i][j] = 0;
        else
          maze[i][j] = -1;
      }
      scanf("\n");
    }

    curB = b, curW = 1;
    d = 0;

    do {
      maze[curB][curW]++;
      if (maze[curB + direction[(d+1)%4][0]][curW + direction[(d+1)%4][1]] != -1) {
        d = (d+1)%4;
      }
      
      while (maze[curB + direction[d][0]][curW + direction[d][1]] == -1) {
        d = (d+3)%4;
      }; 

      curB += direction[d][0];
      curW += direction[d][1];

    } while (curB != b || curW != 1);

    int a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (maze[i][j] == 0)
          a0++;
        else if (maze[i][j] == 1)
          a1++;
        else if (maze[i][j] == 2)
          a2++;
        else if (maze[i][j] == 3)
          a3++;
        else if (maze[i][j] == 4)
          a4++;

      }
    }
    printf("%3d%3d%3d%3d%3d\n", a0, a1, a2, a3, a4);
  }

  return 0;
}

