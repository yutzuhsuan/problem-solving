#include <stdio.h>
int gcd(int a, int b)
{
  int c;
  while (a) {
    c = a;
    a = b%a;
    b = c;
  }
  return b;
}

int main(void)
{
  int gcdSum[505][505];
  int n;

  for (int i = 1; i < 505; i++)
    for (int j = i+1; j < 505; j++)
      gcdSum[i][j] = gcd(i, j);

  while (EOF != scanf("%d", &n) && n) {
    int sum = 0;
    for (int i = 1; i < n; i++)
      for (int j = 1; j <= n; j++)
        sum += gcdSum[i][j];
    printf("%d\n", sum);
  }
  
  return 0;
}
