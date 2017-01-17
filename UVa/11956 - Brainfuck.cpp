#include <stdio.h>
#include <string.h>

int main(void)
{
  int T;
  int mem[100];
  char c;
  scanf("%d\n", &T);

  for (int i = 0; i < T; i++) {
    memset(mem, 0, sizeof(mem));
    printf("Case %d:", i+1);

    int p = 0;
    while (scanf("%c", &c) && c != '\n') {
      if (c == '>') {
        p++;
        p %= 100;
      } else if (c == '<') {
        p--;
        if (p == -1)
          p = 99;
      } else if (c == '+') {
        mem[p]++;
        mem[p] %= 256;
      } else if (c == '-') {
        mem[p]--;
        if (mem[p] == -1)
          mem[p] = 255;
      }
    }

    for (int i = 0; i < 100; i++) {
      printf(" %02X", mem[i]);
    }
    puts("");
  }

  return 0;
}

