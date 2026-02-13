#include <stdlib.h> // exit(), free()
#include <stdio.h>

int main() {
	char* line;// = NULL;
	size_t n = 0;
	ssize_t len = getline(&(line = NULL), &n, stdin);
	if (len == -1) {
		printf("Error on getline()\n");
		exit(1);
	}

	printf("%s\n", line);

	free(line);
}
