#include <stdio.h>
#include <string.h>
int main(void)
{
  int T, N;
  int grid[80][80];
  int prefix[160][160];
  int tmp;

  scanf("%d", &T);

  while (T--) {
    scanf("%d", &N);
    memset(grid, 0, sizeof(grid));
    memset(prefix, 0, sizeof(prefix));
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) {
        scanf("%d", &grid[i][j]);
      }

    for (int i = 1; i <= N*2; i++)
      for (int j = 1; j <= N*2; j++)
        prefix[i][j] = grid[(i-1)%N+1][(j-1)%N+1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];

    int maxx = 0;
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= N; j++)
        for (int k = 0; k <= N; k++)
          for (int l = 0; l <= N; l++)
            if (i + k <= N*2 && j + l <= N*2)
              if (prefix[i+k][j+l] - prefix[i][j+l] - prefix[i+k][j] + prefix[i][j] > maxx)
                maxx = prefix[i+k][j+l] - prefix[i][j+l] - prefix[i+k][j] + prefix[i][j];
    printf("%d\n", maxx);
  }

  return 0;
}

