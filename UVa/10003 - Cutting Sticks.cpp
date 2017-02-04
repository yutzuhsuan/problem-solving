#include <stdio.h>
#include <iostream>
using namespace std;

int l, n;
int c[55];
int dp[55][55];

int cost(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y]; // 要檢查不然會 TLE
  if (!dp[x][y]) return 0; 

  dp[x][y] = 1e9;
  for (int i = x+1; i < y; i++) {
    dp[x][y] = min(dp[x][y], cost(x, i) + cost(i, y) + (c[y]-c[x]));
  }

  return dp[x][y];
}

int main(void)
{

  while (EOF != scanf("%d", &l) && l) {
    scanf("%d", &n);

    c[0] = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d", &c[i]);
    c[n+1] = l;

    for (int i = 0; i <= n+1; i++)
      for (int j = 0; j <= n+1; j++) {
        if (i == j-1) dp[i][j] = 0; // 兩個連在一起的價格是 0
        else dp[i][j] = -1;
      }

    printf("The minimum cutting is %d.\n", cost(0, n+1));
  }

  return 0;
}

