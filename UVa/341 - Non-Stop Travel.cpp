#include <stdio.h>
#include <string.h>

int w[15][15];
int medium[15][15];

int floyd_warshall(int n) {
  for (int k = 1; k <= n; k++) 
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (w[i][k] + w[k][j] < w[i][j]) {
          w[i][j] = w[i][k] + w[k][j];
          medium[i][j] = k;
        }
  return 0;
}

void printPath(int s, int e) {

  if (medium[s][e] == -1)
    return ;
  printPath(s, medium[s][e]);
  printf("%d ", medium[s][e]);
  printPath(medium[s][e], e);
}

int main(void)
{
  int n, m, o, d, start, end, cases = 1;
  
  while(EOF != scanf("%d", &n) && n) {

    for (int i = 0; i < 15; i++)
      for (int j = 0; j < 15; j++) {
        w[i][j] = 9999;
        medium[i][j] = -1;
      }

    for (int i = 1; i <= n; i++) {
      scanf("%d", &m);
      for (int j = 0; j < m; j++) {
        scanf("%d %d", &o, &d); 
        w[i][o] = d;
      }
    }

    floyd_warshall(n);

    scanf("%d %d", &start, &end);

    /*
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        printf("%d ", w[i][j]);
      puts("");
    }
    */
    // printf("%d\n", w[start][end]);

    printf("Case %d: Path = ", cases++);
    printf("%d ", start);
    printPath(start, end);
    printf("%d;", end);
    printf(" %d second delay\n", w[start][end]);

  }
  return 0;
}

