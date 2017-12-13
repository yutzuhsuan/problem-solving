#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main(void)
{
  int T, m;
  int n[105];
  int dp[100005];
  int sum;

  scanf("%d", &T);

  while (T--) {
    scanf("%d", &m);

    sum = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d", &n[i]);
      sum += n[i];
    }

    memset(dp, 0, sizeof(dp));
    int average = sum / 2;
    for (int i = 0; i < m; i++) {
      for (int j = average; j >= n[i]; j--) {
        dp[j] = max(dp[j], dp[j - n[i]] + n[i]);
      }
    }

    printf("%d\n", sum - dp[average] - dp[average]);
  }
  return 0;
}

