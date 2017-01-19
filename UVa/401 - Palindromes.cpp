#include <stdio.h>
#include <string.h>

char notmirror[15] = {'B', 'C', 'D', 'F', 'G', 'K', 'N', 'P', 'Q', 'R', '4', '6', '7', '9', '0'};

int main(void)
{
	char s[105];
	int palindrome, mirror;
	
	while(gets(s) != NULL) {

		palindrome = 1;
		mirror = 1;
		
		for(int i = 0, j = strlen(s)-1; i <= j; i++, j--) {
			
			for(int k = 0; k < 15; k++)
				if(s[i] == notmirror[k] || s[j] == notmirror[k])
					mirror = 0;
			
			if(s[i] == 'E' && s[j] != '3')
					mirror = 0;
			if(s[i] == '3' && s[j] != 'E')
				mirror = 0;
			if(s[i] == '2' && s[j] != 'S')
				mirror = 0;
			if(s[i] == 'S' && s[j] != '2')
				mirror = 0;
			if(s[i] == '5' && s[j] != 'Z')
				mirror = 0;
			if(s[i] == 'Z' && s[j] != '5')
				mirror = 0;
			if(s[i] == 'L' && s[j] != 'J')
				mirror = 0;
			if(s[i] == 'J' && s[j] != 'L')
				mirror = 0;
			
			
			if(s[i] != s[j])
				palindrome = 0;
			
			//printf("%c %c %d\n", s[i], s[j], palindrome);
		}
		//printf("%d %d\n", palindrome, mirror);
		if(palindrome && mirror)
			printf("%s -- is a mirrored palindrome.\n\n", s);
		else if(palindrome && !mirror)
			printf("%s -- is a regular palindrome.\n\n", s);
		else if(!palindrome && mirror)
			printf("%s -- is a mirrored string.\n\n", s);
		else
			printf("%s -- is not a palindrome.\n\n", s);
		
		
	}

	return 0;
}