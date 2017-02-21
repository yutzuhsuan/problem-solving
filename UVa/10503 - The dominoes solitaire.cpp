#include <stdio.h>
#include <string.h>

using namespace std;
int n, m;
int i1, i2, d1, d2;
int p[15], q[15];
int cur[30];
int ans;
int use[15];

void dfs(int i) {

  if (i == n+1) {
    if (cur[i*2-1] == d1)
      ans = 1;
    return ;
  }

  for (int j = 0; j < m; j++) {
    if (p[j] == cur[i*2-1] && !use[j]) {
      cur[i*2] = p[j];
      cur[i*2+1] = q[j];
      use[j] = 1;
      dfs(i+1); 
      use[j] = 0;
    }
    if (q[j] == cur[i*2-1] && !use[j]) {
      cur[i*2] = q[j];
      cur[i*2+1] = p[j];
      use[j] = 1;
      dfs(i+1); 
      use[j] = 0;
    }
  }

  return ;
}

int main(void)
{
  while (EOF != scanf("%d", &n) && n) {
    scanf("%d", &m);
    scanf("%d %d", &cur[0], &cur[1]);
    scanf("%d %d", &d1, &d2);
    for (int i = 0; i < m; i++)
      scanf("%d %d", &p[i], &q[i]);
    ans = 0;
    memset(use, 0, sizeof(use));
    dfs(1);

    if (ans) printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}

