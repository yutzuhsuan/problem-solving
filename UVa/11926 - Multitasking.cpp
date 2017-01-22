#include <stdio.h>
#include <string.h>
int main(void)
{

  int n, m;
  int start, end, repetition;
  int conflict;
  int minute[1000005];

  while (EOF != scanf("%d %d", &n, &m) && (n || m)) {
    memset(minute, 0, sizeof(minute));
    conflict = 0;

    for (int i = 0; i < n; i++) {
      scanf("%d %d", &start, &end);
      if (!conflict) {
        for (int j = start; j < end; j++) {
          if (!minute[j]) minute[j] = 1;
          else {
            conflict = 1; 
            break;
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &start, &end, &repetition);
      if (!conflict) {
        for (int j = 0; j*repetition <= 1000000; j++) {
          for (int k = start; k < end; k++) {
            if (j*repetition+k <= 1000000) {
              if (!minute[j*repetition+k]) minute[j*repetition+k] = 1;
              else {
                conflict = 1;
                break;
              }
            }
          }
        }
      }
    }

    if (conflict)
      printf("CONFLICT\n");
    else
      printf("NO CONFLICT\n");
  }

  return 0;
}

