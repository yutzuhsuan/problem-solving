#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
  string S;
  string SS;
  int Q;
  int match, start, index;
  vector<vector<int> > v(256);
  vector<int>::iterator it;
  
  cin >> S;
  // 把每個字母的 index 都記起來
  for (int i = 0; i < S.size(); i++)
    v[S[i]].push_back(i);

  scanf("%d", &Q);

  while (Q--) {
    cin >> SS;
    match = 1;
    index = -1;
    for (int i = 0; i < SS.size(); i++) {
      it = upper_bound(v[SS[i]].begin(), v[SS[i]].end(), index);
      if (it == v[SS[i]].end()) {
        match = 0;
        break;
      }
      index = it - v[SS[i]].begin();
      index = v[SS[i]][index];
      if (!i) start = index;
    }
    if (!match) printf("Not matched\n");
    else printf("Matched %d %d\n", start, index);
  }

  return 0;
}

