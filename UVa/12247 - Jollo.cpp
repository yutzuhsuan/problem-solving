#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int findNum(int a, int b, int c, int x, int y, int start) {
  while ((start == a || start == b || start == c || start == x || start == y) && start <= 52) {
    start++;
  }

  if (start == 53)
    printf("-1\n");
  else
    printf("%d\n", start);
}

int main(void)
{
  int a, b, c, x, y;

  while(EOF != scanf("%d %d %d %d %d", &a, &b, &c, &x, &y) && (a || b || c || x || y)) {
    priority_queue<int> girl;
    priority_queue<int> boy;

    girl.push(a);
    girl.push(b);
    girl.push(c);

    boy.push(x);
    boy.push(y);

    a = girl.top();
    girl.pop();
    b = girl.top();
    girl.pop();
    c = girl.top();
    girl.pop();

    x = boy.top();
    boy.pop();
    y = boy.top();
    boy.pop();

    if (x > a) {
      if (y > a)
        findNum(a, b, c, x, y, 1);
      else {
        if (y > b)
          findNum(a, b, c, x, y, b);
        else
          findNum(a, b, c, x, y, a);
      }
    } else if (x < a) {
      if (x > b) {
        if (y > b)
          findNum(a, b, c, x, y, b);
        else
          printf("-1\n");
      } else
        printf("-1\n");
    }
  }
  return 0;
}

