/* Hint: LCS */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void)
{
  char tmp;
  int matrix[105][105];
  int mLen, dLen;
  int cnt;
  int t = 0;
  string mom, dad;

  while (getline(cin, mom) && mom != "#") {

    getline(cin, dad);

    mLen = mom.length();
    dLen = dad.length();

    memset(matrix, 0, sizeof(matrix));

    for (int i = 1; i <= mLen; i++) {
      for (int j = 1; j <= dLen; j++)
        if (mom[i-1] == dad[j-1]) {
          matrix[i][j] = matrix[i-1][j-1] + 1;
        } else {
          matrix[i][j] = max(matrix[i-1][j] , matrix[i][j-1]);
        }
    }

    printf("Case #%d: you can visit at most %d cities.\n", ++t, matrix[mLen][dLen]);
  }
  return 0;
}

