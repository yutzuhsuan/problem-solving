/* Hint: LCS */
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void)
{
  int n1, n2;
  int a[105], b[105];
  int matrix[105][105];
  int cnt = 0;

  while (EOF != scanf("%d %d", &n1, &n2) && (n1 || n2)) {
    memset(matrix, 0, sizeof(matrix));
    for (int i = 1; i <= n1; i++)
      scanf("%d", &a[i]);
    for (int i = 1; i <= n2; i++)
      scanf("%d", &b[i]);

    for (int i = 1; i <= n1; i++)
      for (int j = 1; j <= n2; j++)
        if (a[i] == b[j]) matrix[i][j] = matrix[i-1][j-1] + 1;
        else {
          matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
        }

    printf("Twin Towers #%d\n", ++cnt);
    printf("Number of Tiles : %d\n", matrix[n1][n2]);
    puts("");
  }

  return 0;
}

