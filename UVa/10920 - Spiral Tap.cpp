#include <stdio.h>
#include <math.h>
int main(void)
{
  int sz, p;

  while (EOF != scanf("%d %d", &sz, &p) && sz && p) {
    int N = (int)ceil(sqrt(p));
    int middle = ((N*N-(N-1)*(N-1))+1)/2;
    int x, y;


    // printf("%d %d %d\n", p, N, ((N*N-(N-1)*(N-1))+1)/2);
    // printf("%d %d\n", p-(N-1)*(N-1), (2*N+1)/2);

    if (p-(N-1)*(N-1) > middle) {
      if (N%2) {
        x = N;
        y = p-(N-1)*(N-1)-middle+1;
      } else {
        x = 1;
        y = N-(p-(N-1)*(N-1)-middle-1)-1;
      }
    } else {
      if (N%2) {
        x = p-(N-1)*(N-1); 
        y = 1;
      } else {
        x = N-(p-(N-1)*(N-1))+1;
        y = N;
      }
    }

    printf("Line = %d, column = %d.\n", y+(sz-N+1)/2, x+(sz-N)/2);
  }

  return 0;
}

