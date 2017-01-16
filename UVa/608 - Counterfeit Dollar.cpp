#include <stdio.h>
#include <string.h>

char l[3][15], r[3][15], compare[3][5];

int check(int n, int m) {

  int ret = 1;
  int hasAlphabet = 0;

  for (int i = 0; i < 3; i++) {
    int len = strlen(l[i]);
    int ls = 0, rs = 0;
    for (int j = 0; j < len; j++) {
      if (l[i][j] == n+'A')
        ls += m, hasAlphabet = 1;
      if (r[i][j] == n+'A')
        rs += m, hasAlphabet = 1;
    }
    
    if (!strcmp(compare[i], "up") && rs >= ls)
      ret = 0;
    else if (!strcmp(compare[i], "down") && rs <= ls)
      ret = 0;
    else if (!strcmp(compare[i], "even") && rs != ls)
      ret = 0;
  }

  if (ret && hasAlphabet)
    return true;

  return false; 
}

int main(void)
{
  int n;

  scanf("%d\n", &n);

  while (n--) {

    for (int i = 0; i < 3; i++) {
      scanf("%s %s %s", l[i], r[i], compare[i]);
    }

    for (int i = 0; i < 12; i++) {
      if (check(i, 1))
        printf("%c is the counterfeit coin and it is heavy.\n", i+'A');
      else if (check(i, -1))
        printf("%c is the counterfeit coin and it is light.\n", i+'A');
    }

  }

  return 0;
}

