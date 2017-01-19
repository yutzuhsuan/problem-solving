#include <stdio.h>    
int t;  
int n, m;  
long long start, end;  
int num[505];  
int out[505];  
int out_cnt;  
int find_value(int x) { 
	int i; 
    int cnt = n - 1; 
	long long sum;
    for (i = 0; i < m; i ++) {  
		sum = 0;  
		while (sum + num[cnt] <= x) {  
			sum += num[cnt];  
			
			if (cnt == 0)  
				return 1;  
			
			cnt--;  
		}  
    }  
    return 0;  
}  
int main() { 
	int i;
	long long mid, sum;
	int cnt;
    scanf("%d", &t);  
    while (t --) {  
	
		start = 1e9;  
		out_cnt = 0;  

		for(i = 0; i < 505; i++)
			out[i] = 0;
		
		scanf(" %d %d", &n, &m); 
		for (i = 0; i < n; i ++) {  
			scanf("%d", &num[i]);  
			end += num[i];  
			if (start > num[i])  
				start = num[i];  
		} 
		while (start < end) { 
			mid = (start + end) / 2;  
			if (find_value(mid)) {  
				if (end == mid)   
					break;   
				end = mid;  
			}  
			else {  
				if (start == mid)  
					break;  
				start = mid;  
			}  
		}
		
		if (!find_value(mid))  
			mid++;  
			cnt = n - 1; 
			int flag = 0;
			while(true){ 
				sum = 0;  
				while (sum + num[cnt] <= mid) {  
					sum += num[cnt--];  
					if (cnt == -1) {
						flag = 1;
						break; 
					}
				} 
				if(flag)
					break;
				if (cnt != -1) {  
					out[cnt] = 1;  
					out_cnt++;  
				} 
			} 
		
			if (out_cnt != m - 1) {  
				for (i = 0; i < n; i ++)  
					if(!out[i]) {  
						out[i] = 1;  
						out_cnt++;  
						if (out_cnt == m - 1)  
							break;  
					}  
		}  	
	
		
		
		for (i = 0; i < n; i++) {
			if(!i) 
				printf("%d", num[i]);
			else
				printf(" %d", num[i]);  
			if (out[i])
					printf(" /");
		}
		puts("");  
	}
    return 0;  
}