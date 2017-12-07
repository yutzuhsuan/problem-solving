#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
  int N, Q;
  int x, y[10005];
  int c = 0;

  while (EOF != scanf("%d %d", &N, &Q) && (N || Q)) {
    printf("CASE# %d:\n", ++c);
    for (int i = 0; i < N; i++) {
      scanf("%d", &y[i]);
    }
    sort(y, y+N);

    for (int i = 0; i < Q; i++) {
      scanf("%d", &x);
      int found = 0;
      for (int j = 0; j < N; j++) {
        if (y[j] == x) {
          printf("%d found at %d\n", x, j+1);
          found = 1;
          break;
        }
      }
      if (!found) {
        printf("%d not found\n", x);
      }
    }
  }

  return 0;
}
