#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
// open, close, read, write, lseek

int main(void) {
	// File descriptor
	
	// The only things I might ask you about opening for writing, and / or write
	// in general:
	// - to open for writing, you need O_WRONLY
	// - to create the file if it doesn't already exist, you need O_CREAT
	// - write() function works like read(). Must be called in a loop until
	//		you know you're done writing.
	int fd = open("data.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	printf("%d\n", fd);
	
	const char* message = "Hello, World!\n";
	size_t total_bytes_written = 0;
	const size_t message_length = strlen(message);
	while (total_bytes_written < message_length) {
		ssize_t bytes_written = write(
			fd,
			message + total_bytes_written,
			message_length - total_bytes_written
		);
		total_bytes_written += bytes_written;
	}

	close(fd);
}
