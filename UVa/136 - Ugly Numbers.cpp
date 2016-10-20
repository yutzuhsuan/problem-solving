#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;


int main(void)
{
	int ugly[1500];
	int cnt = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	int cnt5 = 0;
	int cur = 0;
	
	ugly[0] = 1;
	while(cur < 1500) {
		for(; ugly[cnt2]*2 <= ugly[cur]; cnt2++){}
		for(; ugly[cnt3]*3 <= ugly[cur]; cnt3++){}
		for(; ugly[cnt5]*5 <= ugly[cur]; cnt5++){}
		
		ugly[++cur] = min(ugly[cnt2]*2, min(ugly[cnt3]*3, ugly[cnt5]*5));
	}
	printf("The 1500'th ugly number is %d.\n", ugly[1499]);
	
	return 0;
}