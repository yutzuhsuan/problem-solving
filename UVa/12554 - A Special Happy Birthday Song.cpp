#include <stdio.h>
int main(void)
{
	int n;
	char name[105][105];
	char song[16][10] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", name[i]);
	}

	for(int i = 0; i < n || i % 16; i++)
		printf("%s: %s\n", name[i%n], song[i%16]);
	

	return 0;
}
