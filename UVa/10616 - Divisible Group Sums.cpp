#include <stdio.h>
#include <string.h>
int n[205];
int N, Q;
int D, M;
int dp[205][15][25];

int solve() {

  memset(dp, 0, sizeof(dp));

  dp[0][0][0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      for (int k = 0; k < D; k++) {
        dp[i][j][k] += dp[i-1][j][k];
        if (j) {
          int t = (D + k - n[i-1] % D) % D; 
          dp[i][j][k] += dp[i-1][j-1][t];
        }
      }
    }
  }

  return dp[N][M][0];
}

int main(void)
{
  int c = 1;

  while (EOF != scanf("%d %d", &N, &Q) && (N || Q)) {
    printf("SET %d:\n", c++);
    for (int i = 0; i < N; i++)
      scanf("%d", &n[i]);
    for (int i = 0; i < Q; i++) {
      scanf("%d %d", &D, &M);
      printf("QUERY %d: %d\n", i+1, solve());
    }
  }

  return 0;
}

