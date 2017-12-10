#include <stdio.h>
int main(void)
{
  int T;
  int price;
  int n;
  int coin;

  scanf("%d", &T);

  while (T--) {
    scanf("%d", &price);
    scanf("%d", &n);

    int dp[10005] = {};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      scanf("%d", &coin);
      for (int j = 10000; j - coin >= 0; j--) {
        if (dp[j] == 0 || dp[j] > dp[j-coin] + 1) {
          if (dp[j-coin]) {
            dp[j] = dp[j-coin] + 1;
          }
        }
      }
    }

    while (!dp[price]) price++;

    printf("%d %d\n", price, dp[price]-1);

  }
  return 0;
}
