#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
  int n;
  string s;

  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    cin >> s;

    sort(s.begin(), s.end());
    do {
      cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));

    puts("");
  }

  return 0;
}

