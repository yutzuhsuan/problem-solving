#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void)
{
  int T;
  int N, M;
  int S;
  int pre, area;
  long long K;
  long long strips[105][105];
  long long colSum[105];
  long long sum, P;
  scanf("%d", &T);

  for (int c = 0; c < T; c++) {

    S = 0;
    P = 1e9;

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        scanf("%lld", &strips[i][j]);

    for (int i = 0; i < N; i++) {
      memset(colSum, 0, sizeof(colSum));
      for (int j = i; j < N; j++) {
        for (int x = 0; x < M; x++) {
          colSum[x] += strips[j][x];
        }

        pre = 0;
        sum = 0;

        for (int x = 0; x < M; x++) {
          sum += colSum[x];

          while (sum > K)
            sum -= colSum[pre++];

          area = (j-i+1) * (x-pre+1);

          if (area > S) {
            S = area;
            P = sum;
          } else if (area == S) {
            P = min(sum, P);
          }
        }
      }
    }

    printf("Case #%d: %d %lld\n", c+1, S, P);
  }

  return 0;
}

