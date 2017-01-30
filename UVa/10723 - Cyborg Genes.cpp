/* LCS變化, 搞好久, input 竟然還有空白 */

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
  int n;
  char a[35], b[35];
  int matrix[35][35];
  int unique[35][35];

  scanf("%d\n", &n);

  for (int k = 0; k < n; k++) {
    gets(a);
    gets(b);
    memset(matrix, 0, sizeof(matrix));
    memset(unique, 0, sizeof(unique));

    for (int i = 0; i < 35; i++) {
      matrix[i][0] = matrix[0][i] = i;
      unique[i][0] = unique[0][i] = 1;
    }

    for (int i = 1; i <= strlen(a); i++)
      for (int j = 1; j <= strlen(b); j++)
        if (a[i-1] == b[j-1]) {
          matrix[i][j] = matrix[i-1][j-1]+1;
          unique[i][j] = unique[i-1][j-1];
        } else {
          matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1]) + 1;
          
          if (matrix[i-1][j] < matrix[i][j-1]) {
            unique[i][j] = unique[i-1][j];
          } else if (matrix[i][j-1] < matrix[i-1][j]) {
            unique[i][j] = unique[i][j-1];
          } else {
            unique[i][j] = unique[i-1][j] + unique[i][j-1];
          }
        }

    printf("Case #%d: %d %d\n", k+1, matrix[strlen(a)][strlen(b)], unique[strlen(a)][strlen(b)]);
  }

  return 0;
}

