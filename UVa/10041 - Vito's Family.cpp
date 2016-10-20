#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int T, r;
	scanf("%d", &T);
	int streetNum[505];
	int sum;
	int mid;
	
	while(T--) {
		scanf("%d", &r);
		for(int i = 0; i < r; i++)
			scanf("%d", &streetNum[i]);
		sort(streetNum, streetNum+r);

		sum = 0;
		
		if(r%2)
			mid = streetNum[r/2];
		else
			mid = streetNum[r/2-1];
		
		for(int i = 0; i < r; i++)
			sum += abs(streetNum[i]-mid);
		
		printf("%d\n", sum);
	}
	
	return 0;
}