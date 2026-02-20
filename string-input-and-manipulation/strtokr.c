#include <stdlib.h> // exit(), free()
#include <stdio.h>
#include <string.h>

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

	// You have to decide what the delimiter is.
	// The tokens are the substrings between the delimiters.
	// "3.14,9.81,21.7"
	

	char** tokens = NULL;
	size_t n_tokens = 0;

	char* saveptr = NULL;
	char* token = strtok_r(line, ",", &saveptr);
	printf("%s\n", line);
	while (token) {
		char* token_copy = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(token_copy, token);
		tokens = realloc(tokens, sizeof(char*) * (n_tokens + 1));
		tokens[n_tokens] = token_copy;
		n_tokens++;

		token = strtok_r(NULL, ",", &saveptr);
	}
	
	free(line);

	for (size_t i = 0; i < n_tokens; ++i) {
		double value = strtod(tokens[i], NULL);
		printf("%lf\n", value * value);
	}

	for (size_t i = 0; i < n_tokens; ++i) {
		free(tokens[i]);
	}

	free(tokens);
	
}
