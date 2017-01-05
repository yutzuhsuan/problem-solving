#include <stdio.h>
int main(void)
{
  int n;
  char ends;

  scanf("%d\n", &n);

  for (int i = 0; i < n; i++) {
    int m = 0, f = 0, moreThanOne = 0;
    while(scanf("%c", &ends) && ends != '\n') {
      if (ends == 'M')
        m++;
      else if (ends == 'F')
        f++;
      else if (ends == ' ')
        moreThanOne = 1;
    }

    if (m == f && moreThanOne)
      printf("LOOP\n");
    else
      printf("NO LOOP\n");
  }

  return 0;
}

