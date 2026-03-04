#include <stdio.h>

int main(void) {
	// File I/O: file input/output
	// Standard I/O: standard input/output
	
	FILE* file_stream = fopen("hello.txt", "a");

	
	fprintf(file_stream, "Hello, %d World!\n", 12);



	fclose(file_stream);
}
