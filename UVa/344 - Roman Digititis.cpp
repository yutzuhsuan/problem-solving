#include <stdio.h>
int i[105];
int v[105];
int x[105];
int l[105];
int c[105];
int iTmp, vTmp, xTmp, lTmp, cTmp;
void count(int num, int check)
{

	switch(num) {
		case 0:
			break;
		case 1:
			if(!check)
				iTmp += 1;
			else if(check == 1)
				xTmp += 1;
			else
				cTmp += 1;
			break;
		case 2:
			if(!check)
				iTmp += 2;
			else
				xTmp += 2;
			break;
		case 3:
			if(!check)
				iTmp += 3;
			else
				xTmp += 3;
			break;
		case 4:
			if(!check)
				vTmp += 1, iTmp += 1;
			else
				lTmp += 1, xTmp += 1;
			break;
		case 5:
			if(!check)
				vTmp += 1;
			else
				lTmp += 1;
			break;
		case 6:
			if(!check)
				vTmp += 1, iTmp += 1;
			else
				lTmp += 1, xTmp += 1;
			break;
		case 7:
			if(!check)
				vTmp += 1, iTmp += 2;
			else
				lTmp += 1, xTmp += 2;
			break;
		case 8:
			if(!check)
				vTmp += 1, iTmp += 3;
			else
				lTmp += 1, xTmp += 3;
			break;
		case 9:
			if(!check)
				xTmp += 1, iTmp += 1;
			else
				cTmp += 1, xTmp += 1;
			break;
	}
	
	return ;
}
int main(void)
{
	int tmp;
	for(int j = 1; j <= 100; j++) {
		tmp = j;
		
		iTmp = 0, vTmp = 0, xTmp = 0, lTmp = 0, cTmp = 0;
		
		count(j/1%10, 0);
		count(j/10%10, 1);
		count(j/100%10, 2);
		
		i[j] = i[j]+i[j-1]+iTmp;
		v[j] = v[j]+v[j-1]+vTmp;
		x[j] = x[j]+x[j-1]+xTmp;
		l[j] = l[j]+l[j-1]+lTmp;
		c[j] = c[j]+c[j-1]+cTmp;
	}
	
	int n;
	while(EOF != scanf("%d", &n) && n)
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i[n], v[n], x[n], l[n], c[n]);
	
	return 0;
}