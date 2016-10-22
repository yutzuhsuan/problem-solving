#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int T;
  char trash;
  vector<int> v;
  char s[10005];

  for (int i = 0; i*i <= 10000; i++) {
    v.push_back(i*i);
  }

  scanf("%d%c", &T, &trash);

  while (T--) {
    // gets 會造成緩衝區溢位的安全問題
    gets(s);

    int pos = find(v.begin(), v.end(), strlen(s)) - v.begin();

    if (pos < v.size()) {
      for (int i = 0; i < pos; i++)
        for (int j = 0; j < pos; j++) {
          printf("%c", s[i+j*pos]);
        }
      printf("\n");
    }
    else {
      printf("INVALID\n");
    }

  }

  return 0;
}
