#include <stdio.h>

int main() {
	char buffer[32];
	fgets(buffer, 32, stdin);
	printf("%s\n", buffer);

	fgets(buffer, 32, stdin);
	printf("%s\n", buffer);
}
