#include <stdio.h>
#include <queue>
using namespace std;

int main(void)
{
  int n, b, sg, sb, tmp;

  scanf("%d", &n);

  while (n--) {
    priority_queue<int> green, blue, gTmp, bTmp;

    scanf("%d %d %d", &b, &sg, &sb);

    while (sg--) {
      scanf("%d", &tmp);
      green.push(tmp);
    }

    while (sb--) {
      scanf("%d", &tmp);
      blue.push(tmp);
    }


    while (green.size() && blue.size()) {
      for (int i = 0; i < b; i++) {
        if (green.size() && blue.size()) {
          if (green.top() == blue.top()) {
            green.pop();
            blue.pop();
          } else if (green.top() > blue.top()) {
            tmp = green.top() - blue.top(); 
            green.pop();
            blue.pop();
            gTmp.push(tmp);
          } else if (blue.top() > green.top()) {
            tmp = blue.top() - green.top();
            green.pop();
            blue.pop();
            bTmp.push(tmp);
          }
        }
      }
      while (!gTmp.empty()) {
        green.push(gTmp.top());
        gTmp.pop();
      }
      while (!bTmp.empty()) {
        blue.push(bTmp.top());
        bTmp.pop();
      }
    }

    if (!green.size() && !blue.size()) {
      printf("green and blue died\n");

    } else if (green.size()) {
      printf("green wins\n");
      while (!green.empty()) {
        printf("%d\n", green.top());
        green.pop();
      }

    } else if (blue.size()) {
      printf("blue wins\n");
      while (!blue.empty()) {
        printf("%d\n", blue.top());
        blue.pop();
      }
    }

    if (n) puts("");
  }

  return 0;
}

