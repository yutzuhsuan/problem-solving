#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
	int b, j;
	bool operator < (const Job& x) const {
		return j > x.j;
	}
};

int main(void)
{

	int N, T = 1;
	int ans, B, P, sum;
	
	while(EOF != scanf("%d", &N) && N) {
	
		vector <Job> v;
		sum = 0;
		ans = 0;
		
		for(int i = 0; i < N; i++) {
			scanf("%d %d", &B, &P);
			v.push_back(Job{B, P});
		}
		sort(v.begin(), v.end());

		for(int i = 0; i < N; i++) {
			sum += v[i].b;
			ans = max(ans, sum+v[i].j);
		}
		
		printf("Case %d: %d\n", T++, ans);
		
	}

	return 0;
}