#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int k, m;

  while(EOF != scanf("%d", &k) && k) {
    scanf("%d", &m);

    vector<int> v;
    int course;
    int pass = 1;

    for (int i = 0; i < k; i++) {
      scanf("%d", &course);
      v.push_back(course);
    }

    int c, r, cnt;
    for(int i = 0; i < m; i++) {
      cnt = 0;
      scanf("%d %d", &c, &r);
      for(int j = 0; j < c; j++) {
        scanf("%d", &course);
        if (find(v.begin(), v.end(), course) != v.end()) {
          cnt++;
        }
      }

      if (cnt < r) {
        pass = 0;
      }

    }

    if (pass) 
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
