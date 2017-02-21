#include <stdio.h>
#include <string.h>
int m, n, k;
int g[105][105];
int color[105];
int maxx;
int ans[105];

int check(int x) {
  for (int i = 0; i < n; i++)
    if (color[i] && g[x][i]) {
      return 0;
    }
  return 1;
}

void dfs(int i)
{
  if (i > maxx) {
    maxx = i;
    for (int j = 0; j < n; j++)
      ans[j] = color[j];
  }

  if (i == n) return ;

  for (int j = 0; j < n; j++) {
    if (check(j) && !color[j]) {
      color[j] = 1;
      dfs(i+1);
      color[j] = 0;
    }
  }
  return ;
}

int main(void)
{
  int x, y;

  scanf("%d", &m);

  while (m--) {
    scanf("%d %d", &n, &k);
    memset(g, 0, sizeof(g));
    for (int i = 0; i < k; i++) {
      scanf("%d %d", &x, &y);
      x--, y--;
      g[x][y] = 1;
      g[y][x] = 1;
    }
    memset(color, 0, sizeof(color));
    maxx = 0;
    dfs(0);

    printf("%d\n", maxx);
    int f = 0;
    for (int i = 0; i < n; i++) {
      if (ans[i]) {
        if (f) printf(" ");
        printf("%d", i+1);
        f = 1;
      }
    }
    puts("");
  }


  return 0;
}
