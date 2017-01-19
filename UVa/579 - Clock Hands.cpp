#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int H, M;
	char c;
	double diff;
	
	while(EOF != scanf("%d %c %d", &H, &c, &M) && (H || M)) {
		
		diff = ((double)H+(double)M/60)*5;
		diff -= M;
		
		if(diff < 0)
			diff = -diff;
		
		if(diff > 30)
			diff = 60-diff;
		
		printf("%.3lf\n", diff*6);
	
	}
}