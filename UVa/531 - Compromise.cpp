/* Hint: LCS */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

vector<string> a;
vector<string> b;
int matrix[105][105];
int pre[105][105];
int whiteSpace;
void print_LCS(int i, int j) {
  if (i == 0 || j == 0)
    return ;

  if (pre[i][j] == 1) {
    print_LCS(i-1, j-1);
    if (whiteSpace)
      printf(" ");
    else
      whiteSpace = 1;
    cout << a[i];
  } else if (pre[i][j] == 2) {
    print_LCS(i-1, j);
  } else if (pre[i][j] == 3) {
    print_LCS(i, j-1);
  }
}

int main(void)
{
  char s[35];
  string tmp;

  while (EOF != scanf("%s", s)) {
    a.clear();
    b.clear();
    memset(matrix, 0, sizeof(matrix));
    memset(pre, 0, sizeof(pre));
    whiteSpace = 0;

    tmp = "";
    a.push_back(tmp);
    b.push_back(tmp);

    tmp = s;
    a.push_back(tmp);

    while (scanf("%s", s) && s[0] != '#') {
      tmp = s;
      a.push_back(tmp);
    }


    while (scanf("%s", s) && s[0] != '#') {
      tmp = s;
      b.push_back(tmp);
    }

    for (int i = 1; i < a.size(); i++)
      for (int j = 1; j < b.size(); j++)
        if (a[i] == b[j]) {
          matrix[i][j] = matrix[i-1][j-1] + 1;
          pre[i][j] = 1;
        } else {
          if (matrix[i-1][j] > matrix[i][j-1]) {
            matrix[i][j] = matrix[i-1][j];
            pre[i][j] = 2; 
          } else {
            matrix[i][j] = matrix[i][j-1];
            pre[i][j] = 3; 
          }
        }

    print_LCS(a.size()-1, b.size()-1);
    puts("");

  }
  return 0;
}

