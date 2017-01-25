#include <stdio.h>
#include <string.h>
#define MAX 1005
int main(void)
{
  char s[MAX];
  char stack[26][MAX];
  int len;
  int cnt;
  int max;
  int cases = 1;

  while (EOF != scanf("%s", s) && strcmp(s, "end")) {
    memset(stack, 0, sizeof(stack));
    len = strlen(s);
    max = 0;

    for (int i = len-1; i >= 0; i--) {
      cnt = 0;
      while (stack[cnt][0] != 0 && s[i] < stack[cnt][stack[cnt][0]]) {
        cnt++;
      }

      stack[cnt][++stack[cnt][0]] = s[i];

      if (cnt > max)
        max = cnt;
    }

    printf("Case %d: ", cases++);
    printf("%d\n", max+1);
  }

  return 0;
}

