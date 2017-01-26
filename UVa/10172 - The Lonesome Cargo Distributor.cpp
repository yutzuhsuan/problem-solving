#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

int main(void)
{
  int t, n, s, q, m, tmp, sum, cur;
  int time;
  scanf("%d", &t);

  deque<int> deq[105];

  while (t--) {
    sum = 0;
    stack<int> car;
    cur = 0;
    time = 0;

    scanf("%d %d %d", &n, &s, &q);
    for (int i = 0; i < n; i++) {
      scanf("%d", &m);
      deq[i].clear();
      for (int j = 0; j < m; j++) {
        scanf("%d", &tmp);
        deq[i].push_back(tmp);
      }
      sum += m;
    }

    /*
    for (int i = 0; i < 5; i++) {
      while (deq[i].size()) {
        printf("%d ", deq[i].front());
        deq[i].pop_front();
      }
      puts("");
    }
    */

    while (sum) {
      while (car.size() || deq[cur].size() < q) {
        if (car.size() && car.top()-1 == cur) {
          // printf("cargo match\n");
          sum--;
          car.pop();
          time++;
        } else if (car.size() && deq[cur].size() < q) {
          // printf("push back %d\n", car.top());
          deq[cur].push_back(car.top());
          car.pop();
          time++;
        } else {
          break;
        }
      }

      while (car.size() < s && deq[cur].size()) {
        // printf("take out %d\n", deq[cur].front());
        car.push(deq[cur].front());
        deq[cur].pop_front();
        time++;
      }

      cur++;
      cur = cur%n;
      if (!sum) {
        break;
      }

      time += 2;
    }

    printf("%d\n", time);
  }

  return 0;
}

