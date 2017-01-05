#include <stdio.h>
#include <string.h>

int decisionToNum(char *decision) {
  if (!strcmp(decision, "+y"))  return 0;
  else if (!strcmp(decision, "-y")) return 1;
  else if (!strcmp(decision, "+z")) return 2;
  else if (!strcmp(decision, "-z")) return 3;
}

const char *  numToDecision(int d) {
  if (d == 0) return "+x";
  else if (d == 1) return "-x";
  else if (d == 2) return "+y";
  else if (d == 3) return "-y";
  else if (d == 4) return "+z";
  else if (d == 5) return "-z";
}

int v[6][4] = {
  {2, 3, 4, 5},
  {3, 2, 5, 4},
  {1, 0, 2, 2},
  {0, 1, 3, 3},
  {4, 4, 1, 0},
  {5, 5, 0, 1},
};

int main(void)
{
  int n;
  char decision[5];

  while (EOF != scanf("%d", &n) && n) {
    int cur = 0;
    for (int i = 0; i < n-1; i++) {
      scanf("%s", decision);
      int d;
      if (strcmp(decision, "No")) {
        d = decisionToNum(decision);
        cur = v[cur][d];
      }
    }

    printf("%s\n", numToDecision(cur));

  }

  return 0;
}

