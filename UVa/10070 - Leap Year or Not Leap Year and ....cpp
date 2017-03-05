#include <stdio.h>
#include <string.h>
int main(void)
{
  char n[1000];
  int f = 0;
  while (EOF != scanf("%s", n)) {

    if (f) puts("");
    else f = 1;

    int o = 0, l = 0;
    int odd = 0, even = 0, sum = 0;
    int len = strlen(n);
    int tmp;

    for (int i = 0; i < len; i++) {
      tmp = n[i]-'0';
      sum += tmp;
      if (i%2) even += tmp;
      else odd += tmp;
    }

    if (n[len-1] == '0' && n[len-2] == '0') {
      tmp = n[len-3]-'0' + (n[len-4]-'0')*10;
      if (tmp % 4 == 0) {
        printf("This is leap year.\n");
        o = 1, l = 1;
      }
    }

    if (n[len-1] != '0' || n[len-2] != '0') {
      tmp = n[len-1]-'0' + (n[len-2]-'0')*10;
      if (tmp % 4 == 0) {
        printf("This is leap year.\n");
        o = 1, l = 1;
      }
    }

    if (sum % 3 == 0 && (n[len-1]-'0') % 5 == 0) {
      printf("This is huluculu festival year.\n");
      o = 1;
    }

    if ((even-odd) % 11 == 0 && (n[len-1]-'0') % 5 == 0 && l) {
      printf("This is bulukulu festival year.\n");
      o = 1;
    }

    if (!o) printf("This is an ordinary year.\n");
  }

  return 0;
}
