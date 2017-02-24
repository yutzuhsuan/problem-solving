#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
  int N, M, Q, L, U, maxx;
  int tmp;
  int range[505][2];

  while (EOF != scanf("%d %d", &N, &M) && (N || M)) {

    vector<vector<int> > v(505);
    vector<int>::iterator lower, upper;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%d", &tmp);
        v[i].push_back(tmp);
      }
    }

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
      scanf("%d %d", &L, &U);
      memset(range, 0, sizeof(range)); 
      maxx = 0;

      // 把每個 row 範圍內的值都記下來
      for (int j = 0; j < N; j++) {
        lower = lower_bound(v[j].begin(), v[j].end(), L);
        upper = upper_bound(v[j].begin(), v[j].end(), U);
        range[j][0] = lower-v[j].begin();
        range[j][1] = upper-v[j].begin();
      }

      // 每個 row 都檢查過一次
      for (int j = 0; j < N; j++) {
        int cnt = 0; // 拿該 row 範圍內第一個數字當左上角
        // 對該 row 而言正方形最大的可能性是 U - L
        for (; cnt <= range[j][1]-range[j][0]; cnt++) { 
          // 檢查對角線 ( 往右往下 ) 是否在範圍內
          if (j+cnt >= N || range[j+cnt][1] <= range[j][0]+cnt) break;
        }
        if (cnt > maxx) maxx = cnt;
      }
      printf("%d\n", maxx);
    }

    printf("-");
    puts("");
  }

  return 0;
}

