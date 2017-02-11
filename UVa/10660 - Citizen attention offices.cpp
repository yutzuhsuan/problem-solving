#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;

int city[5][5];
int s[5], ans[5];
int allSum;

void dfs(int size, int cnt) {
  if (size == 5) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        if (city[i][j]) {
          int tmp = 1e9;
          for (int k = 0; k < 5; k++) {
            int x = s[k]/5;
            int y = s[k]%5;
            if (abs(x - i) + abs(y - j) < tmp)
              tmp = abs(x - i) + abs(y - j);
          }
          sum += tmp*city[i][j];
        }


    if (sum < allSum) {
      allSum = sum;
      for (int i = 0; i < 5; i++)
        ans[i] = s[i];
    }

    return ;
  }

  for (; cnt < 25; cnt++) {
    s[size] = cnt;
    dfs(size+1, cnt+1);
  }
}

int main(void)
{
  int t, n, x, y, p;

  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);

    memset(city, 0, sizeof(city));

    while (n--) {
      scanf("%d %d %d", &x, &y, &p);
      city[x][y] = p;
    }

    allSum = 1e9;
    dfs(0, 0);

    for (int i = 0; i < 5; i++) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    puts("");
  }

  return 0;
}

