#include <stdio.h>
int cards[4][15];
int stop[4];
int points;

int init() {
  for (int i = 0; i < 4; i++)
    stop[i] = 0;

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 15; j++)
      cards[i][j] = 0;

  points = 0;
  return 0;
}

int classify(char * c) {
  int s, n;
  if (c[1] == 'S') s = 0;
  else if (c[1] == 'H') s = 1;
  else if (c[1] == 'D') s = 2;
  else if (c[1] == 'C') s = 3;
 
  if (c[0] == 'A') cards[s][1] = 1, points += 4;
  else if (c[0] == 'J') cards[s][11] = 1, points += 1;
  else if (c[0] == 'Q') cards[s][12] = 1, points += 2;
  else if (c[0] == 'K') cards[s][13] = 1, points += 3;

  cards[s][0]++;

  return 0;
}

int main(void)
{
  char c[5];

  while (EOF != scanf("%s", c)) {

    init();
    classify(c);

    for (int i = 1; i < 13; i++) {
      scanf("%s", c);
      classify(c);
    }

    for (int i = 0; i < 4; i++) {
      if (cards[i][13] && cards[i][0] < 2) {
        points--;
      }
      if (cards[i][12] && cards[i][0] < 3) {
        points--;
      }
      if (cards[i][11] && cards[i][0] < 4) {
        points--;
      }

      if (cards[i][1]) stop[i] = 1;
      if (cards[i][13] && cards[i][0] > 1) stop[i] = 1;
      if (cards[i][12] && cards[i][0] > 2) stop[i] = 1;

      /*
      if (cards[i][1]) {
        stop[i] = 1;
      }

      if (cards[i][13]) {
        if (cards[i][0] < 2) points--;
        else stop[i] = 1;
      }

      if (cards[i][12]) {
        if (cards[i][0] < 3) points--;
        else stop[i] = 1;
      }

      if (cards[i][11]) {
        if (cards[i][0] < 4) points--;
      }
      */
    }

    if (points >= 16 && stop[0] && stop[1] && stop[2] && stop[3]) {
      printf("BID NO-TRUMP\n");
      continue;
    }

    int max = 0;
    for (int i = 0; i < 4; i++) {
      if (cards[i][0] == 2)
        points += 1;
      else if (cards[i][0] <= 1)
        points += 2;

      if (cards[i][0] > cards[max][0]) {
        max = i; 
      }

    }

    if (points < 14)
      printf("PASS\n");
    else {
      if (max == 0) printf("BID S\n");
      else if (max == 1) printf("BID H\n");
      else if (max == 2) printf("BID D\n");
      else if (max == 3) printf("BID C\n");

    }

  }
  
  return 0;
}

