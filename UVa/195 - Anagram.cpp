#include <iostream>
#include <stdio.h>
#include <cctype>
#include <algorithm>
using namespace std;

bool cmp(char x, char y) {
  if (tolower(x) == tolower(y)) {
    return x < y; 
  }
  return tolower(x) < tolower(y);
}

int main(void)
{
  int n;
  string s;

  scanf("%d\n", &n);

  while (n--) {
    cin >> s;
    sort(s.begin(), s.end(), cmp);

    do {
      cout << s << endl;
    } while(next_permutation(s.begin(), s.end(), cmp) );
  }
  return 0;
}

