#include <stdio.h>
#include <string.h>
int main(void)
{
  int T;
  char s[1005];
  int K;
  int ans;
  int sLen;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    ans = 0;
    scanf(" %s", &s);
    scanf("%d", &K);
    sLen = strlen(s);

    for (int i = 0; i <= sLen-K; i++) {
      if (s[i] == '-') {
        for(int j = 0; j < K; j++) {
          if (s[i+j] == '-')
            s[i+j] = '+';
          else
            s[i+j] = '-';
        }
        ans++;
      }
    }

    int impossible = 0;
    for (int i = sLen-K; i < sLen; i++) {
      if (s[i] == '-')
        impossible = 1;
    }

    if (impossible)
      printf("Case #%d: IMPOSSIBLE\n", t);
    else
      printf("Case #%d: %d\n", t, ans);
  }

  return 0;
}

