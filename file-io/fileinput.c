#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct book {
	char* name;
	int num_pages;
};

int main(void) {
	// File I/O: file input/output
	// Standard I/O: standard input/output
	
	FILE* file_stream = fopen("data.txt", "r");
	if (!file_stream) {
		printf("Failed to open data.txt\n");
		exit(1);
	}

	// When you first open a file using "r" or "w" as the second argument
	// to fopen, the file description is given a "file offset" which is
	// initialized to 0. The file offset keeps track of where you're currently
	// at in the file. The file offset is like an "imaginary cursor" that
	// points to a certain place in the file. Any time you read bytes
	// from the file or write bytes to the file, the file offset traverses
	// through the file accordingly.

	struct book* array = NULL;
	size_t num_books = 0;

	_Bool done = 0;
	while (!done) {
		char* line = NULL;
		size_t n = 0;
		ssize_t len = getline(&line, &n, file_stream);
		if (len == -1) {
			if (!feof(file_stream)) {
				printf("Error on getline()\n");
				exit(1);
			}
			free(line);
			break;
		}
		if (len >= 1 && line[len - 1] == '\n') {
			line[len - 1] = '\0';
		}
		if (len >= 2 && line[len - 2] == '\r') {
			line[len - 2] = '\0';
		}

		array = realloc(array, sizeof(struct book) * (num_books + 1));

		char* saveptr = NULL;
		char* token = strtok_r(line, " ", &saveptr);
		
		array[num_books].name = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(array[num_books].name, token);

		token = strtok_r(NULL, " ", &saveptr);
		array[num_books].num_pages = strtol(token, NULL, 10);

		++num_books;
		
		free(line);
	}

	fclose(file_stream);

	printf("%s\n", array[1].name);
	printf("%d\n", array[2].num_pages);

	for (size_t i = 0; i < num_books; ++i) {
		free(array[i].name);
	}
	free(array);
}
