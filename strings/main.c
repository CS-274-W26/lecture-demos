#include <string.h>
#include <stdio.h>

size_t strlen_2(const char* s) {
	size_t idx = 0;
	while (s[idx] != '\0') {
		idx++;
	}
	return idx;
}

int main() {
	// char is an integral type. It represents characters as
	// whole numbers. This is done via a character encoding.
	// The most common character encoding for the basic
	// English character set is ASCII. ASCII has 128 different
	// characters in it.
	char my_favorite_character = 'A';
	//if (my_favorite_character >= 'a' && my_favorite_character <= 'z') {
		
	//}
	printf("%c\n", my_favorite_character);

	// A string is a sequence of zero or more characters.
	// C does not have a string type.
	
	// An array of characters whose contents end in one or more
	// null terminators, then that's a C string.
	
	char my_null_terminator = '\0';

	// %s is a format specifier for a string
	printf("%s, %s!\n", "Hello", "World");

	// For now, all I'm going to show you is how to store constant
	// string literals in variables
	
	// When the program FIRST STARTS, the string literal "Hello, World"
	// is converted into an array of characters with a null terminator
	// at the end. Specifically, that array is stored in the readonly
	// section of the data segment of the process's virtual address
	// space. Then, when the program arrives at this line of code,
	// it takes the memory address of that array and stores it in
	// my_string.
	char const * my_string = "Hello, World!";

	printf("%s\n", my_string);

	// strlen stands for "string length".
	printf("%ld\n", strlen_2(my_string));
}
