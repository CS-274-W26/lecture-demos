#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int x = 12;
	double pi = 3.14;
	const char* str = "Hello, World!";

	char* buffer = malloc(strlen(str) + 15 + 10 + 1);
	if (!buffer) {
		printf("Error on malloc()\n");
		exit(1);
	}
	sprintf(buffer, "%s %lf %d", str, pi, x);

	printf("%s\n", buffer);

	free(buffer);
}
