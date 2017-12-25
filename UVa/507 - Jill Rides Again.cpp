#include <stdio.h>
int main(void)
{
  int b, s, n;
  int mx;
  int start, final_start, final_end;
  int sum;

  scanf("%d", &b);

  for (int r = 1; r <= b; r++) {
    scanf("%d", &s);

    sum = -1;
    mx = 0;
    start = -1;
    final_start = -1;
    final_end = -1;

    for (int i = 1; i < s; i++) {
      scanf("%d", &n);

      if (sum >= 0) sum += n;
      else {
        sum = n;
        start = i;
      }

      if (sum > mx || (sum == mx && i+1-start > final_end - final_start)) {
        mx = sum;
        final_end = i+1;
        final_start = start;
      }
    }
    
    if (mx == 0)
      printf("Route %d has no nice parts\n", r);
    else
      printf("The nicest part of route %d is between stops %d and %d\n", r, final_start, final_end);


  }
  
  return 0;
}
