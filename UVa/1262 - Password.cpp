#include <iostream>
#include <stdio.h>
using namespace std;
char x[6][10], y[6][10];
int cnt;
int K;

bool dfs(int n, string pwd) {
  if (n == 5) {
    if (++cnt == K) {
      cout << pwd << endl;
      return true;
    }
    return false;
  }

  int ax[26] = {};
  int ay[26] = {};
  for (int i = 0; i < 6; i++) {
    ax[x[i][n] - 'A'] = 1;
    ay[y[i][n] - 'A'] = 1;
  }

  for (int i = 0; i < 26; i++)
    if (ax[i] & ay[i]) {
      char c = 'A';
      c += i;
      if (dfs(n+1, pwd+c)) return true;
    }

  return false;
}

int main(void)
{
  int T;
  scanf("%d", &T);

  while (T--) {
    scanf("%d", &K);
    for (int i = 0; i < 6; i++)
      scanf(" %s", x[i]);
    for (int i = 0; i < 6; i++)
      scanf(" %s", y[i]);
    cnt = 0;
    if (!dfs(0, "")) printf("NO\n");

  }

  return 0;
}

