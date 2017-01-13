#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[100];
  char s2[100];
  int sLen, s2Len;
  int eaten, cnt;

  while(gets(s)) {
    if (!strcmp(s, "DONE"))
      break;
    sLen = strlen(s);

    cnt = 0;
    for (int i = 0; i < sLen; i++)
      if (s[i] >= 'a' && s[i] <= 'z')
        s2[cnt++] = s[i];
      else if (s[i] >= 'A' && s[i] <= 'Z')
        s2[cnt++] = s[i] - 'A' + 'a';

    s2[cnt++] = '\0';

    eaten = 0;
    s2Len = strlen(s2);
    for (int i = 0; i < s2Len/2; i++)
      if (s2[i] != s2[s2Len-1-i]) {
        eaten = 1;
      }

    if (eaten)
      printf("Uh oh..\n");
    else
      printf("You won't be eaten!\n");

  }
  return 0;
}

