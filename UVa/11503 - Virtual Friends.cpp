/* 原來暴力過不了了= = reference: http://programming-study-notes.blogspot.tw/2014/03/uva-11503-virtual-friends.html */
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
int set[200005];
int cnt[200005];

int FindRoot(int x)
{
  if (x == set[x]) return x;
  return set[x] = FindRoot(set[x]);
}

void print(int x, int y) {
  // printf("%d %d\n", x, y);
  x = FindRoot(x);
  y = FindRoot(y);
  // printf("%d %d\n", x, y);

  if (x != y) {
    set[x] = y;
    cnt[y] += cnt[x];
  }

  cout << cnt[y] << endl;
}

int main(void)
{
  int n, t;
  string a, b;

  scanf("%d", &n);
  while (n--) {
    scanf("%d", &t);
    for (int i = 0; i <= t*2; i++) {
      set[i] = i;
      cnt[i] = 1;
    }

    map<string, int> m;
    int j = 1;

    for (int i = 0; i < t; i++) {
      cin >> a >> b;
      if (!m[a]) m[a] = j++;
      if (!m[b]) m[b] = j++;
      print(m[a], m[b]);

      /*
      for (int i = 0; i <= t; i++)
        printf("%d ", set[i]);
      puts("");
      for (int i = 0; i <= t; i++)
        printf("%d ", cnt[i]);
      puts("");
      */
    }
  }

  return 0;
}

