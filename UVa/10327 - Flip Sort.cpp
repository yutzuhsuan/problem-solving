#include <stdio.h>
int main(void)
{
	int N;
	int a[1005];
	int tmp;
	
	while(EOF != scanf("%d", &N)) {
		
		for(int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		
		int cnt = 0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N-i-1; j++)
				if(a[j] > a[j+1]) {
					tmp = a[j];
					a[j] = a[j+1];
					a[j+1] = tmp;
					cnt++;
				}
		printf("Minimum exchange operations : %d\n", cnt);
	}
	
	return 0;
}