#include <stdio.h>
#include <vector>
using namespace std;

int N, m, maxSum;
int CD[25];
vector<int> ans, tmp;

void findTrack(int id, int sum) {
  if (sum > maxSum) {
    maxSum = sum;
    ans = tmp;
  }

  for (int i = id; i < m; i++) {
    if (sum + CD[i] <= N) {
      tmp.push_back(CD[i]);
      findTrack(i+1, sum+CD[i]);
      tmp.pop_back();
    }
  }
  return ;
}

int main(void)
{

  while (EOF != scanf("%d", &N)) {
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
      scanf("%d", &CD[i]);

    maxSum = 0;
    tmp.clear();
    ans.clear();

    findTrack(0, 0); // findTrack(id, sum)

    vector<int>::iterator it;
    for (it = ans.begin(); it != ans.end(); it++)
      printf("%d ", *it);
    printf("sum:%d\n", maxSum);
  }

  return 0;
}

