#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int compare(const void *a, const void *b) {
  /*
  const int *a = *(const int **)pa;
  const int *b = *(const int **)pb;
  */

  if (((const int *)a)[1] == ((const int *)b)[1]) {
    if (((const int *)a)[2] == ((const int *)b)[2])
      return ((const int *)a)[0] > ((const int *)b)[0];
    else
      return ((const int *)a)[2] > ((const int *)b)[2];

  } else
    return ((const int *)a)[1] < ((const int *)b)[1];

}

int main(void)
{

  int n;
  int contestants, problems, times;
  char state;
  char tmp;
  char trash;
  int people[105][5];
  int record[105][10];

  scanf("%d\n\n", &n);

  for (int l = 0; l < n; l++) {
    if (l)
      puts("");

    memset(record, 0, sizeof(record));
    memset(people, 0, sizeof(people));

    for (int i = 0; i < 105; i++)
      people[i][0] = 1000;

    while (EOF != scanf("%c", &tmp)) {
      if (tmp == '\n')
        break;
      contestants = tmp-'0';
      while (scanf("%c", &tmp) && tmp != ' ' && tmp != '\n') {
        contestants *= 10;
        contestants += tmp-'0';
      }
      scanf(" %d %d %c%c", &problems, &times, &state, &trash);

      if (state == 'C') {
        if (record[contestants][problems] != -1) {
          people[contestants][1]++;
          people[contestants][2] += (record[contestants][problems]*20 + times);
        }
        record[contestants][problems] = -1;
      } else if (state == 'I') {
        if (record[contestants][problems] != -1) {
          record[contestants][problems]++;
        }
      }
      people[contestants][0] = contestants;
    }

    qsort(people, 102, sizeof people[0], compare);

    for (int i = 0; people[i][0] != 1000; i++)
      printf("%d %d %d\n", people[i][0], people[i][1], people[i][2]);

  }


  return 0;
}

