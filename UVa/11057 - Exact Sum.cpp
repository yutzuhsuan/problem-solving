#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
  int n, money, tmp, m;
  
  while (EOF != scanf("%d", &n)) {
    vector<int> v;
    vector<int>::iterator b1, b2;
    pair<int, int> p;

    for (int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      v.push_back(tmp);
    }
    scanf("%d", &money);

    m = 1e9;
    for (b1 = v.begin(); b1 != v.end(); b1++) {
      b2 = find(v.begin(), v.end(), money-*b1);
      if (b2 != v.end() && b2 != b1) {
        if (abs(*b2-*b1) < m) {
          m = abs(*b2-*b1);
          p = pair<int, int> (min(*b1, *b2), max(*b1, *b2));
        }
      }
    }
    
    printf("Peter should buy books whose prices are %d and %d.\n\n", p.first, p.second);
  }

  return 0;
}

