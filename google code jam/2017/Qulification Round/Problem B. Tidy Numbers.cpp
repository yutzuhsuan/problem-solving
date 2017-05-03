#include <stdio.h>
#include <string.h>
int main(void)
{
  int T;
  int nLen;
  char N[25];

  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    scanf(" %s", &N);
    nLen = strlen(N);
    int modify = 1;
    while (modify) {
      modify = 0;
      int c = 0;
      for (int i = 0; i < nLen-1; i++) {
        if (N[i] > N[i+1]) {
          if (!c) {
            N[i]--;
            if (N[i] == '0'-1)
              N[i] = '9';
            c = 1;
          }
          N[i+1] = '9';
          modify = 1;
        }
      }
    }

    int prefix = 0;
    for (prefix = 0; prefix < nLen; prefix++)
      if (N[prefix] != '0')
        break;
      

    printf("Case #%d: %s\n", t, N+prefix);
  }

  return 0;
}

