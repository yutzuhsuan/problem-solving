#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
  int T;
  long long s[5];

  scanf("%d", &T);

  for (int i = 1; i <= T; i++) {
    printf("Case %d: ", i);
    scanf("%lld %lld %lld", &s[0], &s[1], &s[2]);
    sort(s, s+3);

    if (s[0] + s[1] <= s[2]) {
      printf("Invalid\n");
    } else if (s[0] == s[1] && s[1] == s[2]) {
      printf("Equilateral\n");
    } else if (s[0] == s[1] || s[1] == s[2]) {
      printf("Isosceles\n");
    } else {
      printf("Scalene\n");
    }
  }

  return 0;
}
