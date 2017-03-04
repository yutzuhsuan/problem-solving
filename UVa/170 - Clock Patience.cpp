#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
int main(void)
{
  string s;

  while (cin >> s && s != "#") {

    list<string> l[15];
    l[13].push_back(s);

    for (int i = 0; i < 4; i++)
      for (int j = 13; j > 0; j--) {
        if (i || j != 13) {
          cin >> s;
          l[j].push_back(s);
        }
      }

    int cur = 13;
    int target;
    int cnt = 0;
    string exposed;

    while (1) {

      if (l[cur].empty()) {
        printf("%02d,", cnt);
        cout << exposed << endl;
        break;
      }

      exposed = l[cur].front();
      if (exposed[0] >= '0' && exposed[0] <= '9')
        target = exposed[0] - '0';
      else if (exposed[0] == 'K')
        target = 13;
      else if (exposed[0] == 'Q')
        target = 12;
      else if (exposed[0] == 'J')
        target = 11;
      else if (exposed[0] == 'T')
        target = 10;
      else if (exposed[0] == 'A')
        target = 1;

      cnt++;

      l[cur].pop_front();
      cur = target;
    }
  }

  return 0;
}

