#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int main(void)
{
  int c, l, m, len, ans, cur, volume;
  char pos[10];

  scanf("%d", &c);

  while (c--) {
    scanf("%d %d", &l, &m);
    deque<int> deq[2];

    for (int i = 0; i < m; i++) {
      scanf("%d %s", &len, pos);
      if (!strcmp(pos, "left")) {
        deq[0].push_back(len);
      } else {
        deq[1].push_back(len);
      }
    }

    ans = 0;
    cur = 0;
    while (deq[0].size() || deq[1].size()) {
      volume = 0;
      // printf("%d\n", cur);
      while (deq[cur].size() && deq[cur].front() && volume + deq[cur].front() <= l*100) {
        volume += deq[cur].front();
        // printf("%d %d\n", ans, deq[cur].front());
        deq[cur].pop_front();
      }
      ans++;
      cur++;
      cur %= 2;
    }

    printf("%d\n", ans);
  }

  return 0;
}

