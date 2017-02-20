#include <stdio.h>
int n, p;
int nums[25];
int ans;

void dfs(int sum, int i) {
  if (sum > n) return ;

  if (sum == n) ans = 1;

  for (;i < p; i++) {
    dfs(sum+nums[i], i+1);
  }

}

int main(void)
{
  int t;

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%d", &p);
    for (int i = 0; i < p; i++)
      scanf("%d", &nums[i]);

    ans = 0;
    dfs(0, 0);

    if (ans) printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}

