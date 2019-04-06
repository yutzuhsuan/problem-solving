#include <stdio.h>
using namespace std;

int main(void)
{
  int T, N;
  char move;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++) {
    scanf("%d", &N);
    printf("Case #%d: ", i);
    for (int j = 0; j < N*2-2; j++) {
      scanf(" %c", &move);
      if (move == 'E')
        printf("S");
      else if (move == 'S')
        printf("E");
    }
    puts("");
  }

  return 0;
}
