#include <stdio.h>
#include <algorithm>
using namespace std;
int between(int a, int b)
{
	if(b-a < 0)
		return (b-a+40)*9;
	else
		return (b-a)*9;
}
int main(void)
{
	int p0, p1, p2, p3;
	while(EOF != scanf("%d %d %d %d", &p0, &p1, &p2, &p3) && (p0 || p1 || p2 || p3))
		printf("%d\n", between(p1, p0)+between(p1, p2)+between(p3, p2)+1080);
	return 0;
}