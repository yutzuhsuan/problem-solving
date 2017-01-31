#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#define MAX 100
using namespace std;

int main(void)
{
  int a[MAX], b[MAX];
  int aLen, bLen;
  char trash;

  while (EOF != scanf("%d%c", &a[0], &trash)) {
    aLen = 1;
    if (trash != '\n') {
      while (scanf("%d%c", &a[aLen++], &trash) && trash != '\n') {};
    }
    sort(a, a+aLen);

    bLen = 0;
    while (scanf("%d%c", &b[bLen++], &trash) && trash != '\n') {};
    sort(b, b+bLen);

    vector<int> v(MAX);
    vector<int>::iterator it;
    it = set_intersection(a, a+aLen, b, b+bLen, v.begin());
    v.resize(it-v.begin());

    if (aLen == bLen && v.size() == aLen)
      printf("A equals B\n");
    else if (aLen > bLen && v.size() == bLen)
      printf("B is a proper subset of A\n");
    else if (aLen < bLen && v.size() == aLen)
      printf("A is a proper subset of B\n");
    else if (v.size())
      printf("I'm confused!\n");
    else
      printf("A and B are disjoint\n");
  }

  return 0;
}

