#include <stdlib.h> // exit(), free()
#include <stdio.h>

int main() {
	char* line = NULL;
	size_t n = 0;
	ssize_t len = getline(&line, &n, stdin);
	if (len == -1) {
		printf("Error on getline()\n");
		free(line);
		exit(1);
	}

	if (line[len - 1] == '\n') {
		line[len - 1] = '\0';
		len--;
	}
	if (line[len - 1] == '\r') {
		line[len - 1] = '\0';
		len--;
	}

	printf("%s\n", line);

	free(line);
}
