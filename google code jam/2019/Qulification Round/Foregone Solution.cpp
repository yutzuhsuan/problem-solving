#include <stdio.h>
#include <string.h>

using namespace std;

int main(void)
{
  int T;
  char n[105];
  char a[105];
  char b[105];

  int n_len;

  scanf("%d", &T);

  for (int i = 1; i <= T; i++) {
    scanf("%s", n);

    n_len = strlen(n);
    for (int j = 0; j < n_len; j++) {
      if (n[j]== '4') {
        a[j] = '2';
        b[j] = '2';
      } else {
        a[j] = n[j];
        b[j] = '0';
      }
    }
    a[n_len] = '\0';
    b[n_len] = '\0';


    printf("Case #%d: %s ", i, a);
    int notZero = 0;
    for (int j = 0 ; j < n_len ; j++) {
      if (b[j] != '0' || notZero) {
        notZero = 1;
        printf("%c", b[j]);
      }
    }
    puts("");
  }

  return 0;  
}
