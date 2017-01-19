#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

// 用 vector 過不了 QQ
// 參考了 set 就可以了 QQ 
// http://garbagecode.blogspot.tw/2014/05/201459-uva-12356-army-buddies.html
// 明明一樣阿 QQ

int main(void)
{
  int S, B, start, end;

  set<int> v;
  set<int>::iterator it;

  while (EOF != scanf("%d %d", &S, &B) && S && B) {

    v.clear();
    for (int i = 0; i <= S+1; i++)
      v.insert(i);


    while (B--) {
      scanf("%d %d", &start, &end);

      // set<int>::iterator it;

      /*
      for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
      cout << "fuck" << endl;
      */


      // it = lower_bound(v.begin(), v.end(), start);

      it = v.find(start);
      it--;
      if (*(it)) printf("%d ", *(it));
      else printf("* ");

      it = v.find(end);
      it++;
      if (*it != S+1) printf("%d\n", *it);
      else printf("*\n");

      for (int i = start; i <= end; i++) {
        if (v.find(i) != v.end()) {
          v.erase(i);
        }
      }

    }
    printf("-\n");

  }

  return 0;
}

