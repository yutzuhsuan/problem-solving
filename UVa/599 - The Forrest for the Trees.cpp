#include <stdio.h>
#include <string.h>

int forest[30][30];
int alphabet[30];

void findTree(int n) {
  for (int i = 0; i < 26; i++)
    if (alphabet[i] && forest[n][i]) {
      alphabet[i] = 0;
      findTree(i);
    }
  return ;
}

int main(void)
{
  int n;
  int tree, acorn;
  char start, end;
  char asterisk[100];
  char tmp[100];
  scanf("%d", &n);

  while (n--) {
    memset(alphabet, 0, sizeof(alphabet));
    memset(forest, 0, sizeof(forest));
    tree = 0;
    acorn = 0;

    while (scanf(" %s", tmp) && tmp[0] != '*') {
      start = tmp[1];
      end = tmp[3];

      forest[start-'A'][end-'A'] = 1;
      forest[end-'A'][start-'A'] = 1;
      alphabet[start-'A'] = 1;
      alphabet[end-'A'] = 1;
    }

    scanf(" %s", tmp);
    for (int i = 0; i < strlen(tmp); i+=2) {
      if (!alphabet[tmp[i]-'A'])
        acorn++;
    }

    for (int i = 0; i < 26; i++) {
      if (alphabet[i]) {
        findTree(i);
        tree++;
      }
    }

    printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);

  }

  return 0;
}

