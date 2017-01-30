#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
  string a, b;
  int aCnt[30], bCnt[30];

  while (getline(cin, a)) {
    getline(cin, b);

    memset(aCnt, 0, sizeof(aCnt));
    memset(bCnt, 0, sizeof(bCnt));

    for (int i = 0; i < a.length(); i++)
      aCnt[a[i]-'a']++;
    for (int i = 0; i < b.length(); i++)
      bCnt[b[i]-'a']++;

    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < min(aCnt[i], bCnt[i]); j++)
        printf("%c", i+'a');
    }
    puts("");

  }

  return 0;
}

