#include <stdio.h>
#include <string.h>
int main(void)
{
	char n1[30], n2[30];
	int s1, s2;
	
	while(gets(n1) != NULL) {
		gets(n2);
		
		s1 = 0;
		s2 = 0;
		
		for(int i = 0; i < strlen(n1); i++)
			if(n1[i] >= 'a' && n1[i] <= 'z')
				s1 += n1[i]-'a'+1;
			else if(n1[i] >= 'A' && n1[i] <= 'Z')
				s1 += n1[i]-'A'+1;
			
		for(int i = 0; i < strlen(n2); i++)
			if(n2[i] >= 'a' && n2[i] <= 'z')
				s2 += n2[i]-'a'+1;
			else if(n2[i] >= 'A' && n2[i] <= 'Z')
				s2 += n2[i]-'A'+1;
		
		int tmp;
		while(s1/10) {
			tmp = s1;
			s1 = 0;
			while(tmp) {
				s1 += tmp%10;
				tmp /= 10;
			}
		}
		
		while(s2/10) {
			tmp = s2;
			s2 = 0;
			while(tmp) {
				s2 += tmp%10;
				tmp /= 10;
			}
		}
		printf("%.2lf %%\n", s1 > s2 ? (double)s2*100/(double)s1 : (double)s1*100/(double)s2);
		
	}
	
	return 0;
}