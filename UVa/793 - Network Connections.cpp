#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
  int n, m, right, wrong, a, b;
  int computers[1000];
  char c;
  char trash;
  scanf("%d", &n);

  while (n--) {
    right = 0, wrong = 0;

    scanf("%d%c", &m, &c);

    for (int i = 0; i <= m; i++)
      computers[i] = i;

    while (EOF != scanf("%c", &c) && c != '\n') {
      scanf("%d%d%c", &a, &b, &trash);
      if (c == 'c') {
        int tmp = min(computers[a], computers[b]);
        int x = computers[a];
        int y = computers[b];
        for (int j = 1; j <= m; j++) {
          if (computers[j] == x || computers[j] == y)
            computers[j] = tmp;
        }
      } else if (c == 'q') {
        if (computers[a] == computers[b]) {
          right++;
        } else {
          wrong++;
        }
      }
    }


    printf("%d,%d\n", right, wrong);
    if (n) puts("");
  }


  return 0;
}

