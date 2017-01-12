#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m[105][105];
int main(void)
{
  int n;
  char tmp[5];
  scanf("%d", &n);

  memset(m, 0, sizeof(m));

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      scanf("%s", tmp);
      m[i][j] = tmp[0] == 'x' ? 9999 : atoi(tmp);
      m[j][i] = tmp[0] == 'x' ? 9999 : atoi(tmp);
    }
  }

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (m[i][k] + m[k][j] < m[i][j])
          m[i][j] = m[i][k] + m[k][j];

  int max = 0;
  for (int i = 0; i < n; i++) {
    if (m[i][0] > max)
      max = m[i][0];
  }
  printf("%d\n", max);


  return 0;
}

