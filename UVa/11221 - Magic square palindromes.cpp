#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

int main(void)
{
  int T, s1Len, s2Len, cnt, k;
  char s1[10005];
  char s2[10005];
  char s3[105][105];

  scanf("%d\n", &T);

  for (int i = 1; i <= T; i++) {

    printf("Case #%d:\n", i);

    gets(s1);

    // printf("%s\n", s1);

    cnt = 0;
    s1Len = strlen(s1);
    for (int j = 0; j < s1Len; j++)
      if (s1[j] >= 'a' && s1[j] <= 'z')
        s2[cnt++] = s1[j];

    s2[cnt++] = '\0';
    s2Len = strlen(s2);
    k = (int)sqrt(s2Len);

    if ((int)sqrt(s2Len)*(int)sqrt(s2Len) != s2Len) {
      printf("No magic :(\n");
    } else {

      cnt = 0;
      for (int j = 0; j < k; j++)
        for (int o = 0; o < k; o++)
          s3[j][o] = s2[cnt++];

      int noMagic = 0;
      for (int j = 0; j < k/2; j++)
        for (int o = 0; o < k/2; o++)
          if (s3[j][o] != s3[o][j] || s3[j][o] != s3[k-1-o][k-1-j] || s3[j][o] != s3[k-1-j][k-1-o]) {
            noMagic = 1;
          }
          

      if (noMagic)
        printf("No magic :(\n");
      else
        printf("%d\n", k);

    }

    // printf("%d %lf\n", strlen(s2), sqrt(strlen(s2)));

  }

  return 0;
}

