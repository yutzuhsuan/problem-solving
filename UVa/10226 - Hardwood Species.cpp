#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main(void) {
  int n, cnt;
  string s;

  scanf("%d\n", &n);
  while (n--) {
    map<string, double> m;
    cnt = 0;

    while (getline(cin, s) && s != "") {
      if (m[s])
        m[s]++;
      else
        m[s] = 1.0;
      cnt++;
    }

    for (map<string, double>::iterator it = m.begin(); it != m.end(); it++) {
      cout << it->first << " ";
      printf("%.4lf\n", it->second/cnt*100);
    }

    if (n) puts("");
  }

  return 0;
}

