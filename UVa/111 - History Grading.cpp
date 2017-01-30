/* Hint: http://www.csie.ntnu.edu.tw/~u91029/LongestCommonSubsequence.html */
/* 是說這題把 input 吃進來才是重點吧                                       */
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void)
{
  int n, tmp;
  int my[25], ans[25];
  int matrix[25][25];
  int next = 1;
  char trash;

  scanf("%d", &n);

  while (next) {
    next = 0;

    for (int i = 1; i <= n; i++) {
      scanf(" %d", &tmp);
      ans[tmp] = i;
    }

    while (EOF != scanf("%d%c", &tmp, &trash)) {
      if (trash == '\n') {
        n = tmp;
        next = 1;
        break;
      }
      my[tmp] = 1;

      for (int i = 2; i <= n; i++) {
        scanf(" %d", &tmp);
        my[tmp] = i;
      }

      memset(matrix, 0, sizeof(matrix));


      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          if (ans[i] == my[j]) {
            matrix[i][j] = matrix[i-1][j-1] + 1;
          } else {
            matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
          }

      /*
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          printf("%d ", matrix[i][j]);
        }
        puts("");
      }
      */
      printf("%d\n", matrix[n][n]);
    }

  }
  
  return 0;
}

