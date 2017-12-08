#include <stdio.h>

int p[33000] = {};
void prime() {

  for (int i = 2; i < 33000; i++) {
    if (!p[i]) {
      for (int j = 2; i * j < 33000; j++) {
        p[i*j] = 1;
      }
    }
  }

  return ;
}

int main(void)
{
  prime();
  
  int n;

  while (EOF != scanf("%d", &n) && n) {
    int ans = 0;
    for (int i = 2; i <= n/2; i++) {
      if (!p[i] && !p[n-i])
        ans++;
    }
    printf("%d\n", ans);
  }

  return 0;
}
