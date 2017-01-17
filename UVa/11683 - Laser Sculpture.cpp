#include <stdio.h>
int main(void)
{
  int A, C;

  while (EOF != scanf("%d %d", &A, &C) && A) {

    int sum = 0, next;

    for (int i = 0; i < C; i++) {
      scanf("%d", &next);
      if (A - next > 0)
        sum += A-next;
      A = next;
    }

    printf("%d\n", sum);


  }
  return 0;
}

