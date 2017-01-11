#include <stdio.h>
#include <string.h>

int main(void)
{
  int n, s1Len, s2Len;
  char s1[100], s2[100];
  char letters[30];

  while (EOF != scanf("%d\n", &n) && n != -1) {
    printf("Round %d\n", n);

    scanf("%s", s1);
    scanf("%s", s2);

    s1Len = strlen(s1);
    s2Len = strlen(s2);

    memset(letters, 0, sizeof(letters));

    int g = 0;
    int check = 0;

    for (int i = 0; i < s2Len; i++) {
      char a = s2[i];
      int isGuess = 0;
      check = 0;
      if (letters[a-'a'] == 0) {
        for (int j = 0; j < s1Len; j++) {
          if (s1[j] == a) {
            s1[j] = '0';
            isGuess = 1;
          }
        }
        letters[a-'a'] = 1;
        if (!isGuess)
          g++;
      }

      for (int j = 0; j < s1Len; j++)
        if (s1[j] != '0')
          check = 1;

      if (!check)
        break;
    }

    if (check && g < 7)
      printf("You chickened out.\n");
    else if (g >= 7)
      printf("You lose.\n");
    else
      printf("You win.\n");

  }

  return 0;
}

