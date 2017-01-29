#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
  int n, m, a, b;
  long long sum;

  while (EOF != scanf("%d", &n) && n) {
    priority_queue<int, vector<int>, greater<int> > pq;
    sum = 0;

    while (n--) {
      scanf("%d", &m);
      pq.push(m);
    }

    while (pq.size() > 1) {
      a = pq.top();
      pq.pop();
      b = pq.top();
      pq.pop();
      sum += a+b;
      pq.push(a+b);
    }
    
    printf("%lld\n", sum);
  }

  return 0;
}

