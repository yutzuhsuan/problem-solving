#include <stdio.h>
#define MAX 10005
int main(void)
{

  int T, N;
  int h[MAX], w[MAX], upper[MAX], lower[MAX];
  int increase, decrease;

  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    scanf("%d", &N);

    increase = 0, decrease = 0;
    for (int i = 0; i < N; i++)
      scanf("%d", &h[i]);
    for (int i = 0; i < N; i++)
      scanf("%d", &w[i]);

    for (int i = 0; i < N; i++) {
      upper[i] = lower[i] = w[i];
      for (int j = 0; j < i; j++) {
        if (h[j] < h[i] && upper[i] < upper[j] + w[i]) {
          upper[i] = upper[j] + w[i];
        }
        if (h[j] > h[i] && lower[i] < lower[j] + w[i]) {
          lower[i] = lower[j] + w[i];
        }
      }
      if (upper[i] > increase) increase = upper[i];
      if (lower[i] > decrease) decrease = lower[i];

    }

    if (increase >= decrease) {
      printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, increase, decrease);
    } else {
      printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, decrease, increase);
    }
  }


  return 0;
}

