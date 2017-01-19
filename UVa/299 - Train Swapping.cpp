#include <stdio.h>

int main(void)
{
	int N, L, cnt;
	int a[55];
	int tmp;
	
	scanf("%d", &N);
	while(N--) {
		cnt = 0;
		
		scanf("%d", &L);
		for(int i = 0; i < L; i++)
			scanf("%d", &a[i]);
	
		for(int i = 0; i < L; i++)
			for(int j = 0; j < L-i-1; j++)
				if(a[j] > a[j+1]) {
					tmp = a[j];
					a[j] = a[j+1];
					a[j+1] = tmp;
					cnt++;
				}
		printf("Optimal train swapping takes %d swaps.\n", cnt);
	}
	
	return 0;
}