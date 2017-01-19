#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

int main(void)
{
  int N, K, M, price, sum;
  char c;

  scanf("%d", &N);
  while (N--) {
    sum = 0;
    map<char, int> paids; 
    scanf("%d\n", &K);
    for (int i = 0; i < K; i++) {
      scanf("%c %d\n", &c, &price);
      paids.insert(pair<char, int>(c, price));
    }

    scanf("%d\n", &M);
    while (M--) {
      string line;
      getline(cin, line);
      for (int i = 0; i < line.size(); i++)
        if (paids[line[i]])
          sum += paids[line[i]];
    }

    printf("%d.%02d$\n", sum/100, sum%100);
  }

  return 0;
}

