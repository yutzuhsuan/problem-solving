#include <stdio.h>
int main(void)
{
	char c;
	
	while(EOF != scanf("%c", &c)) {
		
		if(c >= 'A' && c <= 'Z')
			c = c-'A'+'a';
		switch(c) {
			case '3': printf("1"); break;
			case 'e': printf("q"); break;
			case 'd': printf("a"); break;
			case 'c': printf("z"); break;
			case '4': printf("2"); break;
			case 'r': printf("w"); break;
			case 'f': printf("s"); break;
			case 'v': printf("x"); break;
			case '5': printf("3"); break;
			case 't': printf("e"); break;
			case 'g': printf("d"); break;
			case 'b': printf("c"); break;
			case '6': printf("4"); break;
			case 'y': printf("r"); break;
			case 'h': printf("f"); break;
			case 'n': printf("v"); break;
			case '7': printf("5"); break;
			case 'u': printf("t"); break;
			case 'j': printf("g"); break;
			case 'm': printf("b"); break;
			case '8': printf("6"); break;
			case 'i': printf("y"); break;
			case 'k': printf("h"); break;
			case ',': printf("n"); break;
			case '9': printf("7"); break;
			case 'o': printf("u"); break;
			case 'l': printf("j"); break;
			case '.': printf("m"); break;
			case '0': printf("8"); break;
			case 'p': printf("i"); break;
			case ';': printf("k"); break;
			case '/': printf(","); break;
			case '-': printf("9"); break;
			case '[': printf("o"); break;
			case '\'': printf("l"); break;
			case '=': printf("0"); break;
			case ']': printf("p"); break;
			case '\\': printf("["); break;
			case '2': printf("`"); break;
			case ' ': printf(" "); break;
			case '\n': printf("\n"); break;
			/*
			case '': printf(""); break;
			case '': printf(""); break;
			case '': printf(""); break;
			case '': printf(""); break;
			case '': printf(""); break;
			case '': printf(""); break;
			case '': printf(""); break;
			*/
		}
	
	
	}

	return 0;
}