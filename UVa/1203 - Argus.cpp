#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(void)
{
  int qnum, r, n, f, s;
  char c[10];
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  map<int, int> m;
  
  while (EOF != scanf("%s", c) && strcmp(c, "#")) {
    scanf("%d %d", &qnum, &r);
    pq.push(pair<int, int> (r, qnum));
    m[qnum] = r;
  }

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("%d\n", pq.top().second);
    f = pq.top().first;
    s = pq.top().second;
    pq.push(pair<int, int> (((f/m[s])+1)*m[s], s));
    pq.pop();
  }

  return 0;
}

