#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
  int n, m;
  int connections[30][30];
  int cnt[30];
  int tmp[30];
  int ans;
  char a, b, c;

  while (EOF != scanf("%d", &n)) {
    scanf("%d", &m);
    scanf(" %c %c %c", &a, &b, &c);
    memset(connections, 0, sizeof(connections));
    memset(tmp, 0, sizeof(tmp));
    ans = 0;

    vector<int> v;
    vector<int>::iterator it;
    v.push_back(a-'A');
    v.push_back(b-'A');
    v.push_back(c-'A');
    tmp[a-'A'] = 1;
    tmp[b-'A'] = 1;
    tmp[c-'A'] = 1;

    for (int i = 0; i < m; i++) {
      scanf(" %c %c", &a, &b);
      connections[a-'A'][b-'A'] = 1;
      connections[b-'A'][a-'A'] = 1;
    }


    while (1) {
      memset(cnt, 0, sizeof(cnt));
      int isBreak = 0;
      for (it = v.begin(); it != v.end(); it++) {
        for (int i = 0; i <= 26; i++) {
          if (connections[*it][i]) {
            cnt[i]++;
          }
        }
      }


      for (int i = 0; i <= 26; i++) {
        if (cnt[i] >= 3 && !tmp[i]) {
          v.push_back(i);
          tmp[i] = 1;
          isBreak = 1; 
        }
      }

      if (!isBreak)
        break;

      ans++;

      if (v.size() == n) {
        break;
      }
    }

    if (v.size() == n) printf("WAKE UP IN, %d, YEARS\n", ans);
    else printf("THIS BRAIN NEVER WAKES UP\n");
  }
  return 0;
}

