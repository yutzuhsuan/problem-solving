#include <stdio.h>
#include <string.h>
#define MAX 100

char s[MAX];
char target[MAX];
char stack[MAX];
char ans[MAX*2];
int len;
int sCnt, tCnt;
int top;

int anagram(int n) {

  if (n == len*2) {
    for (int i = 0; i < len*2; i++) {
      if (i) printf(" ");
      printf("%c", ans[i]);
    }
    puts("");
    return 0;
  }

  if (sCnt < len) {
    stack[top++] = s[sCnt++];
    ans[n] = 'i';
    anagram(n+1);
    top--, sCnt--;
  }

  if (stack[top-1] == target[tCnt]) {
    char tmp = stack[top-1];
    top--, tCnt++;
    ans[n] = 'o';
    anagram(n+1); 
    stack[top++] = tmp, tCnt--;
  }


  return 0;
}

int main(void)
{
  while (EOF != scanf("%s", s)) {
    scanf("%s", target);
    len = strlen(s);
    sCnt = 0, tCnt = 0, top = 0;
    printf("[\n");
    if (strlen(s) == strlen(target))
      anagram(0);
    printf("]\n");
  }
  return 0;
}

