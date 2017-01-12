#include <stdio.h>
#include <string.h>

int player[1000005];
int snack[110];
int main(void)
{
  int t, a, b, c, dies, start, end;
  scanf("%d", &t);

  while (t--) {

    for (int i = 0; i < 1000005; i++)
      player[i] = 1;
    memset(snack, 0, sizeof(snack));

    scanf("%d %d %d", &a, &b, &c);

    for (int i = 0; i < b; i++) {
      scanf("%d %d", &start, &end);
      snack[start] = end;
      // snack[end] = start;
    }

    int cur = 0, gameOver = 0;
    for (int i = 0; i < c; i++) {
      cur = i % a;
      scanf("%d", &dies);

      if (!gameOver) {
        player[cur] += dies;
        player[cur] = snack[player[cur]] ? snack[player[cur]] : player[cur];
      }

      if (player[cur] >= 100) {
        player[cur] = 100;
        gameOver = 1;
      }
    }

    for (int i = 0; i < a; i++)
      printf("Position of player %d is %d.\n", i+1, player[i]);

  }

  return 0;
}

