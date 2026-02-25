#include <stdio.h>

#define PRINT printf

#define MY_MACRO

#define PRINT_INTEGER(x) printf("%d\n", x)

#define define_square_function(t) t square_##t(t x) {\
	return x * x;\
}

define_square_function(int)
define_square_function(float)
define_square_function(double)

#undef define_square_function

// define_square_function(long int)

// 1. Preprocessing. The C preprocessor processes preprocessing
//		directives to transform the source code BEFORE passing it
//		off to the compiler. Preprocessing directives are just lines
//		of code that start with #.
// 2. Compilation
// 3. Linking

void foo(void) {
	#define HELLO "Hello, World!\n"
}

int main(void) {
	PRINT(MY_MACRO"Hello, World!\n"MY_MACRO);
	
	PRINT_INTEGER(17);

	PRINT(HELLO);

	printf("%d\n", square_int(17));

	// The following macros support conditional compilation
	// #ifdef
	// #ifndef
	// #endif
	// #if
	// #elif
	// #else

#undef HELLO
#ifndef HELLO
	printf("This code survived!\n");

#endif

	int x = 100;

#ifdef DEBUG
	printf("value of x on line 58: %d\n", x);
#endif

#define y 13
#if y + 1 == 13
	printf("a!\n");
#elif y + 1 == 14
	printf("b!\n");
#else
	printf("c!\n");
#endif

}
