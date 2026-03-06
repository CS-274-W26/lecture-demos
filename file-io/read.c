#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
// open, close, read, write, lseek

int main(void) {
	// File descriptor
	int fd = open("data.txt", O_RDONLY, 0);
	printf("%d\n", fd);
	
	char buffer[256];
	_Bool done = 0;
	size_t total_bytes_read = 0;
	while (!done) {
		ssize_t bytes_read = read(
			fd,
			buffer + total_bytes_read,
			255 - total_bytes_read
		);
		total_bytes_read += bytes_read;
		if (bytes_read == 0) {
			done = 1;
		}
	}
	buffer[total_bytes_read] = '\0';

	printf("%s\n", buffer);

	close(fd);
}
