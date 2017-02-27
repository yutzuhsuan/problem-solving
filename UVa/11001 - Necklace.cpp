#include <stdio.h>
#include <math.h>
int main(void)
{
  int vt, v0;

  while (EOF != scanf("%d %d", &vt, &v0) && (vt || v0)) {

    int p = 0;
    double Max = 0;

    for (int i = 1; i < vt; i++) {
      // 小於 0 不能開根號
      if ((double)vt/i - v0 < 0) break;
      // 算出 sum
      double sum = 0.3*sqrt((double)vt/i - v0)*i;
      // sum 有多種可能 output 為 0
      if (fabs(Max - sum) <= 1e-10) {
        p = 0;
        break;
      }
      // sum 比較好就更新 p
      else if (sum > Max) {
        Max = sum;
        p = i;
      }
    }
    printf("%d\n", p);
  }
  return 0;
}

