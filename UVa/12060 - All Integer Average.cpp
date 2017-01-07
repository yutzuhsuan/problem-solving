#include <stdio.h>

int gcd(int a,int b) {

  if (a % b == 0) {
    return b < 0 ? -b : b;
  }

  return gcd(b, a%b);

}

int numLen(int n) {
  if (!n) {
    return 0;
  }

  int ret = 1;
  while (n/10) {
    ret++;
    n /= 10;
  }
  return ret;
}

int main(void)
{
  int n, nLen, a, sum, g, avg, avgLen, remainder, remainderLen;
  int c = 1;

  while (EOF != scanf("%d", &n) && n) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      sum += a;
    }
    g = gcd(sum, n);
    sum /= g;
    n /= g;

    avg = sum/n;
    avgLen = numLen(avg);

    remainder = sum%n;
    remainderLen = numLen(remainder);

    nLen = numLen(n);
    
    printf("Case %d:\n", c++);

   
    // layer 1
    if (remainder) {
      if (sum < 0)
        printf("  ");
      for (int i = 0; i < avgLen+nLen-remainderLen; i++)
        printf(" ");
      printf("%d\n", remainder > 0 ? remainder : -remainder);
    }

    // layer 2
    if (sum < 0)
      printf("- "); 
    if (avg)
      printf("%d", avg < 0 ? -avg : avg);
    if (remainder)
      for (int i = 0; i < nLen; i++)
        printf("-");
    if (sum == 0)
      printf("0");
    printf("\n");


    
    // layer 3
    if (remainder) {
      if (sum < 0)
        printf("  ");
      for (int i = 0; i < avgLen; i++)
        printf(" ");
      printf("%d\n", n);
    }

  }

  return 0;
}

