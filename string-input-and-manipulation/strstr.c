#include <stdlib.h>
#include <string.h>
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


	
	if (strcmp(line, "thepassword") == 0) {
		printf("You're in.\n");
	} else {
		printf("Wrong password.\n");
	}


	char* copy = calloc(len + 1, sizeof(char));
	strcpy(copy, line);
	
	// "Hello abc goodabcbye"
	if (strstr(line, "abc")) {
		printf("Your string contains abc in it\n");
	}


	free(copy);
	free(line);
}
