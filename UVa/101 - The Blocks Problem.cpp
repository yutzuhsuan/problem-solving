#include <stdio.h>
#include <stdlib.h>
int m[30][30];
int n;

void move(int a, int b)
{
	int cnt = 0, b_index;
	int buf[30];
	int flag;
	
	for(int i = 0; i < n; i++) {
		flag = 0;
		for(int j = 1; j <= m[i][0]; j++) {
			if(flag) {
				buf[cnt++] = m[i][j];
				m[i][j] = -1;
			}
			if(m[i][j] == a) {
				buf[cnt++] = a;
				m[i][j] = -1;
				flag = 1;
			}
			
			if(m[i][j] == b) {
				b_index = i;
			}
		}
		if(flag) {
			m[i][0] -= cnt;
		}
	}	
	
	for(int j = 0; j < cnt; j++) {
		m[b_index][m[b_index][0]+j+1] = buf[j];
	}
	
	m[b_index][0] += cnt;
	//printf("%d %d\n", m[b_index][0], cnt);
	return ;
}

void remove(int a)
{
	int flag = 0, cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= m[i][0]; j++) {
			if(flag) {
				m[m[i][j]][1] = m[i][j];
				m[m[i][j]][0] = 1;
				m[i][j] = -1;
				cnt++;
			}
			if(m[i][j] == a)
				flag = 1;
			
		}
		
		if(flag) {
			m[i][0] -= cnt;
			return ;
		}
	}
	
	return ;
}

int at_same_place(int a, int b)
{
	int flag1, flag2;
	
	for(int i = 0; i < n; i++) {
		flag1 = 0;
		flag2 = 0;
		for(int j = 1; j <= m[i][0]; j++) {
			if(m[i][j] == a)
				flag1 = 1;
			if(m[i][j] == b)
				flag2 = 1;
			if(flag1 && flag2)
				return 1;
		}
		if(flag1 || flag2)
			return 0;
	}
	
	return 0;
}

int main(void)
{
	char c1, c2, c3, c4, c5, c6, c7, c8;
	int n1, n2;
	
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		m[i][0] = 1;
		m[i][1] = i;
	}
	
	while(EOF != scanf(" %c %c %c %c", &c1, &c2, &c3, &c4) && c1 != 'q') {
		
		scanf("%d", &n1);
		scanf(" %c %c %c %c", &c5, &c6, &c7, &c8);
		scanf("%d", &n2);
		
		if(n1 == n2)
			continue;
		if(at_same_place(n1, n2))
			continue;
		
		if(c1 == 'm')
			remove(n1);
		if(c5 == 'o' && c6 == 'n')
			remove(n2);

		move(n1, n2);
	
	
	
	}

	
	for(int i = 0; i < n; i++) {
		printf("%d:", i);
		for(int j = 1; j <= m[i][0]; j++)
			printf(" %d", m[i][j]);
		puts("");
	}
	
	return 0;
}