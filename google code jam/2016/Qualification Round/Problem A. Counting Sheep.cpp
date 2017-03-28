#include <stdio.h>
#include <string.h>

int digit[10];
int check(long long N) {

  while (N) {
    digit[N%10] = 1;
    N /= 10;
  }

  for (int i = 0; i < 10; i++) {
    if (!(digit[i]))
      return 0;
  }

  return 1;
}

int main(void)
{
  int T;
  long long N;
  scanf("%d", &T);

  for (int t = 0; t < T; t++) {
    printf("Case #%d: ", t+1);
    scanf("%lld", &N);
    if (!N) {
      printf("INSOMNIA\n");
      continue;
    }

    memset(digit, 0, sizeof(digit));
    long long sum = 0;
    while (1) {
      sum += N;
      if (check(sum)) {
        printf("%d\n", sum);
        break;
      }
    }

  }

  return 0;
}

