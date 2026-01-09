#include <stdio.h> // Preprocessing directive

/*jfds
 * afjdsajfd
 * safjdsa
 * fjdsa
 * fjdsa
 * fdjsa
 * fdsjafdsajf
 * dsa
 */

// gcc is a C build tool. It does several things
// 1. It preprocesses the C source code
// 2. It then compiles that C source code into object code
// 3. It links all the object files necessary for the executable together
// 	to actually create the executable.

int main() {
	// The main function is the entrypoint to the program. Every C program
	// must have exactly one main() function. Its return type must be
	// int. The main function automatically returns 0 if it ends without
	// otherwise returning something.
	//
	// The return value of main indicates the program's exit code. By
	// convention, an exit code of 0 means "success".
	
	// The first argument to printf is the format string. It is a string
	// potentially containing placeholders known as "format specifiers"
	// Format specifiers:
	// 	%d is a placeholder for a decimal value (integer)
	//
	printf(
		"Hello%d, "
			"Wo%drld!",
		10,
		5
	);
	fflush(stdout);
	printf("\n");

	// Every process (running instance of a program) has a special
	// file stream known as standard output. printf() writes some text
	// to standard output. By default, standard output is "hooked up"
	// to the terminal.
	//
	// Standard output, by default, is line-buffered.
	
	// In C, the following primitive types are available:
	// int: Integer
	// float: Floating point number
	// long int (long): Integer, but it gets more memory
	// double: Double-precision floating point number
	// char: Character. Exactly one byte. Usually, it can be
	// 	between -128 and 127.
	//
	// Literals.
	// 5, 10, -12: int
	// 3.14, -5.7: double
	// 3.14f, -5.7f: float
	// 5l, 10l: long int
	// 'a': char <-- I'll remind you of this on Tuesday
}
