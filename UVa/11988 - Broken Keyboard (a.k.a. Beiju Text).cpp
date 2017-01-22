#include <stdio.h>
#include <string.h>
#include <list>
using namespace std;
int main(void)
{
  char s[100005];
  char tmp[100005];
  int cnt, len, position;
  list<char> l;
  list<char>::iterator it;

  while (EOF != scanf("%s", s)) {
    len = strlen(s); 
    position = 0;
    cnt = 0;
    l.clear();

    for (int i = 0; i <= len; i++) {
      if (s[i] == '[' || s[i] == ']' || i == len) {
        if (!position) {
          for (int j = 0; j < cnt; j++) {
            l.push_back(tmp[j]);
          }
        } else {
          for (int j = cnt-1; j >= 0; j--) {
            l.push_front(tmp[j]);
          }
        }

        if (s[i] == '[')
          position = 1;
        else
          position = 0;
        cnt = 0;
        continue;
      }
      /*
      else if (s[i] == ']' || i == len) {
        if (position) {
          for (int j = cnt-1; j >= 0; j--) {
            l.push_front(tmp[j]);
          }
          cnt = 0;
          position = 0;
          continue;
        }
        continue;
      }
      */

      tmp[cnt++] = s[i];
    }

    for (it = l.begin(); it != l.end(); it++)
      printf("%c", *it);
    puts("");

  }

  return 0;
}

