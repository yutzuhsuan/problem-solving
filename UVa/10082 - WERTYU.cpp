#include <stdio.h>
int main(void)
{
	char c;
	
	while(EOF != scanf("%c", &c)) {
		switch(c) {
			case '1': printf("`"); break;
			case '2': printf("1"); break;
			case 'W': printf("Q"); break;
			case 'S': printf("A"); break;
			case 'X': printf("Z"); break;
			case '3': printf("2"); break;
			case 'E': printf("W"); break;
			case 'D': printf("S"); break;
			case 'C': printf("X"); break;
			case '4': printf("3"); break;
			case 'R': printf("E"); break;
			case 'F': printf("D"); break;
			case 'V': printf("C"); break;
			case '5': printf("4"); break;
			case 'T': printf("R"); break;
			case 'G': printf("F"); break;
			case 'B': printf("V"); break;
			case '6': printf("5"); break;
			case 'Y': printf("T"); break;
			case 'H': printf("G"); break;
			case 'N': printf("B"); break;
			case '7': printf("6"); break;
			case 'U': printf("Y"); break;
			case 'J': printf("H"); break;
			case 'M': printf("N"); break;
			case '8': printf("7"); break;
			case 'I': printf("U"); break;
			case 'K': printf("J"); break;
			case ',': printf("M"); break;
			case '9': printf("8"); break;
			case 'O': printf("I"); break;
			case 'L': printf("K"); break;
			case '.': printf(","); break;
			case '0': printf("9"); break;
			case 'P': printf("O"); break;
			case ';': printf("L"); break;
			case '/': printf("."); break;
			case '-': printf("0"); break;
			case '[': printf("P"); break;
			case '\'': printf(";"); break;
			case '=': printf("-"); break;
			case ']': printf("["); break;
			case '\\': printf("]"); break;
			case ' ': printf(" "); break;
			default : printf("\n"); break;
		}

	}
	return 0;
}