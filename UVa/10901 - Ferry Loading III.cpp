#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
  int c, n, t, m, arrive;
  int sum;
  int cur;
  int carCnt;
  char pos[7];
  int ans[10005];
  int wait;

  scanf("%d", &c);
  
  while (c--) {
    scanf("%d %d %d", &n, &t, &m);

    deque<pair<int, int> > banks[2]; // 0 is left, 1 is right

    for (int i = 0; i < m; i++) {
      scanf("%d %s", &arrive, pos);
      if (!strcmp(pos, "left")) {
        banks[0].push_back(pair<int, int> (arrive, i));
      } else {
        banks[1].push_back(pair<int, int> (arrive, i));
      }
    }

    sum = 0;
    cur = 0;
    while (banks[0].size() || banks[1].size()) {
      carCnt = 0;

      if (banks[cur].size() && banks[cur].front().first <= sum) {
        while (banks[cur].size() && banks[cur].front().first <= sum && carCnt < n) {
          ans[banks[cur].front().second] = sum+t;
          banks[cur].pop_front();
          carCnt++;
        }

        cur++;
        cur %= 2;
        sum += t;
      } else {
        int l = banks[0].size() ? banks[0].front().first : 1e9;
        int r = banks[1].size() ? banks[1].front().first : 1e9;

        if (sum < min(l, r)) {
          sum = min(l, r);  
        }

        if (l < r) {
          if (cur) sum += t;
          cur = 0;
        }
        else {
          if (!cur) sum += t;
          cur = 1;
        }
      }
    }

    for (int i = 0; i < m; i++)
      printf("%d\n", ans[i]);

    if (c)
      puts("");
  }

  return 0;
}

