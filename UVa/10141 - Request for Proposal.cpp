#include <stdio.h>
#include <string.h>
int main(void)
{
  int n, p;
  char requirement[100]; 
  char name[100]; 
  double d;
  int r;
  int cnt = 1;

  while(EOF != scanf("%d %d\n", &n, &p) && (n || p)) {

    int max = 0; 
    double highest = 0.0;
    char best[100];

    for(int i = 0; i < n; i++) {
      fgets(requirement, sizeof(requirement), stdin);
    }

    while (p--) {
      fgets(name, sizeof(name), stdin);
      scanf("%lf %d\n", &d, &r);
      if (r > max || (r == max && d < highest)) {
        strcpy(best, name); 
        max = r;
        highest = d;
      }

      while(r--) {
        fgets(requirement, sizeof(requirement), stdin);
      }

    }

    if (cnt != 1)
      printf("\n");
    printf("RFP #%d\n", cnt++);
    printf("%s", best);

  }

  return 0;
}

