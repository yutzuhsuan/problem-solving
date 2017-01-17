#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
  char s[100];
  char s2[100];

  while (EOF != scanf("%s", s)) {
    vector<string> v;
    int len = strlen(s);
    int ans = 0;
    for (int i = 0; i < len; i++)
      for (int j = i+1; j <= len; j++) {
        int check = 1;
        for (int k = i, m = j-1; k < j; k++, m--) {
          if (s[k] != s[m]) {
            check = 0;
            break;
          }
        }
        if (check) {
          int cnt = 0;
          // printf("%d %d\n", i, j);
          for (int k = i; k < j; k++)
            s2[cnt++] = s[k];
          s2[cnt++] = '\0';
          string s3 = s2;
          if (find(v.begin(), v.end(), s3) == v.end()) {
            ans++;
            v.push_back(s2);
          }
        }
      }


    printf("The string '%s' contains %d palindromes.\n", s, ans);
  }

  return 0;
}

