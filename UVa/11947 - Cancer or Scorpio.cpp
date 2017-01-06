#include <stdio.h>
int month[13] = {
  0,
  31,
  28,
  31,
  30,
  31,
  30,
  31,
  31,
  30,
  31,
  30,
  31,
};

int begin[13][2] = {
  {0, 0},
  {1, 21},
  {2, 20},
  {3, 21},
  {4, 21},
  {5, 22},
  {6, 22},
  {7, 23},
  {8, 22},
  {9, 24},
  {10, 24},
  {11, 23},
  {12, 23},
};

char *sign[] = {
  "",
  "aquarius",
  "pisces",
  "aries",
  "taurus",
  "gemini",
  "cancer",
  "leo",
  "virgo",
  "libra",
  "scorpio",
  "sagittarius",
  "capricorn",
};

const char * findSign(int m, int d) {
  if (begin[m][1] > d) {
    if (m == 1)
      return sign[12];
    else
      return sign[m-1];
  }
  else
    return sign[m];

}

int main(void)
{
  int n, digits, d, m, y;

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {

    scanf("%d", &digits);

    y = digits % 10000;
    d = digits % 1000000 / 10000;
    m = digits / 1000000;

    d += 280;

    while (d > month[m]) {
      if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        month[2] = 29;
      } else {
        month[2] = 28;
      }

      d -= month[m++];

      if (m == 13) {
        y += 1;
        m = 1;
      }

    }

    printf("%d %02d/%02d/%d %s\n", i, m, d, y, findSign(m, d));
    
  }

  return 0;
}

