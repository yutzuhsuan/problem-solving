#include <stdio.h>
int main(void)
{
  int n;
  int nums[1005];
  int s[1005];
  int check = 0;

  while (EOF != scanf("%d", &n) && n) {

    while (1) {
      for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        if (!nums[0])
          break;
      }
      if (!nums[0])
        break;

      int cnt = 0, top = 0;
      for (int i = 0; i < n; i++) {
        if (i+1 == nums[cnt]) {
          cnt++;
        } else {
          s[top++] = i+1;
        }

        if (cnt == n)
          break;

        while (nums[cnt] == s[top-1]) {
          top--;
          cnt++;
        }
      }

      if (top == 0 && cnt == n)
        printf("Yes\n");
      else
        printf("No\n");
    }
    puts("");
  }
  return 0;
}

