#include <stdio.h>

int s, d;
int month[12];
int ans;

void dfs(int i) {

  // 從五月開始的每個月都要檢查 
  // 當月前五個月(含)的總和是否為虧損
  if (i > 4) {
    int tmp = 0;
    for (int j = i-5; j < i; j++) {
      tmp += month[j];
    }
    if (tmp >= 0) return ;
  }


  // 到年底了，可以看看整年是否營利
  // 若營利高於目前答案，就更新答案
  if (i == 12) {
    int sum = 0;
    for (int j = 0; j < 12; j++) sum += month[j];
    if (sum > ans) ans = sum;
    return ;
  }


  // 這個月營利或虧損各試一次
  month[i] = s;
  dfs(i+1);
  month[i] = -d;
  dfs(i+1);

  return ;
}

int main(void)
{

  while (EOF != scanf("%d %d", &s, &d)) {
    ans = -1e9;
    dfs(0);

    if (ans >= 0) printf("%d\n", ans);
    else printf("Deficit\n");
  }

  return 0;
}

