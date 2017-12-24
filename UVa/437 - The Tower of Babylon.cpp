#include <stdio.h>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int> > v;

bool cmp (tuple<int, int, int> a, tuple<int, int, int> b) {
  int x1 = get<0>(a), x2 = get<0>(b),
      y1 = get<1>(a), y2 = get<1>(b),
      z1 = get<2>(a), z2 = get<2>(b);

  if (x1 < x2) return true;
  else if (x1 == x2 && y1 < y2) return true;
  else if (x1 == x2 && y1 == y2 && z1 < z2) return true;
  else return false;

}


int main(void)
{
  int n;
  int kase = 0;
  int x, y, z;
  int LIS[200];


  while (EOF != scanf("%d", &n) && n) {

    v.clear();

    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &x, &y, &z);
      v.push_back(tuple<int, int, int>(x, y, z));
      v.push_back(tuple<int, int, int>(y, x, z));
      v.push_back(tuple<int, int, int>(x, z, y));
      v.push_back(tuple<int, int, int>(z, x, y));
      v.push_back(tuple<int, int, int>(y, z, x));
      v.push_back(tuple<int, int, int>(z, y, x));
    }

    sort(v.begin(), v.begin()+6*n, cmp);

    for (int i = 0; i < n*6; i++)
      LIS[i] = 1;

    for (int i = 0; i < n*6; i++) {
      LIS[i] = get<2>(v[i]);
      for (int j = 0; j < i; j++) {
        int x1 = get<0>(v[i]), x2 = get<0>(v[j]),
            y1 = get<1>(v[i]), y2 = get<1>(v[j]);

        if (x1 > x2 && y1 > y2 && LIS[j] + get<2>(v[i]) >  LIS[i])
          LIS[i] = LIS[j] + get<2>(v[i]);
      }
    }

    int mx = 0;
    for (int i = 0; i < n*6; i++)
      if (mx < LIS[i])
        mx = LIS[i];

    printf("Case %d: maximum height = %d\n", ++kase, mx);

  }

  return 0;
}

