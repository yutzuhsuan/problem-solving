#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char s[1000000];

  while(EOF != scanf("%s", s) && strcmp(s, "END")) {
    
    int cnt = 0;

    while (strlen(s) != atoi(s)) {
      int len = strlen(s);
      snprintf(s, sizeof(s), "%d", len);
      cnt++;
    }

    printf("%d\n", cnt+1);
    
  }

  return 0;
}

