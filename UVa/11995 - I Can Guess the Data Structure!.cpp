#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
int main(void)
{
  int n, cmd, x;
  int isPQ, isS, isQ;

  while (EOF != scanf("%d", &n) && n) {
    priority_queue<int> pq;
    stack<int> s;
    queue<int> q;
    isPQ = 1;
    isS = 1;
    isQ = 1;
    
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &cmd, &x);

      if (isPQ) {
        if (cmd == 1) {
          pq.push(x);
        } else {
          if (pq.size() && pq.top() == x)
            pq.pop();
          else
            isPQ = 0;
        }
      }
      if (isS) {
        if (cmd == 1) {
          s.push(x);
        } else {
          if (s.size() && s.top() == x)
            s.pop();
          else
            isS = 0;
        }
      }
      if (isQ) {
        if (cmd == 1) {
          q.push(x);
        } else {
          if (q.size() && q.front() == x)
            q.pop();
          else
            isQ = 0;
        }
      }
    }

    if (isPQ && !isS && !isQ) {
      printf("priority queue\n");
    } else if (!isPQ && isS && !isQ) {
      printf("stack\n");
    } else if (!isPQ && !isS && isQ) {
      printf("queue\n");
    } else if (!isPQ && !isS && !isQ) {
      printf("impossible\n");
    } else {
      printf("not sure\n");
    }
  }

  return 0;
}

