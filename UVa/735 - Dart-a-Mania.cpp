#include <stdio.h>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;
int main(void)
{
  int n, permutations;
  int tmp[3];

  set<int> s1, s2, s3;
  set<int>::iterator i1, i2, i3;

  for (int i = 0; i <= 20; i++)
    for (int j = 1; j <= 3; j++) {
      s1.insert(i*j);
      s2.insert(i*j);
      s3.insert(i*j);
    }
  s1.insert(50);
  s2.insert(50);
  s3.insert(50);


  while (EOF != scanf("%d", &n) && n > 0) {

    set<tuple<int, int, int> > combinations;
    permutations = 0;

    for (i1 = s1.begin(); i1 != s1.end(); i1++)
      for (i2 = s2.begin(); i2 != s2.end(); i2++)
        for (i3 = s3.begin(); i3 != s3.end(); i3++)
          if (*i1 + *i2 + *i3 == n) {
            permutations++;
            tmp[0] = *i1, tmp[1] = *i2, tmp[2] = *i3; 
            sort(tmp, tmp+3);
            // printf("%d %d %d\n", tmp[0], tmp[1], tmp[2]);
            combinations.insert(tuple<int, int, int> (tmp[0], tmp[1], tmp[2]));
          }

    if (combinations.size()) {
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, combinations.size());
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, permutations);
    } else {
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
    }


    printf("**********************************************************************");
    puts("");
  }

  printf("END OF OUTPUT\n");

  return 0;
}

