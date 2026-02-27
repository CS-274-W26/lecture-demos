#include <stdio.h>

// 1. Preprocessing. The preprocessor acts on one translation unit
//		at a time.
// 2. Compilation. The compiler acts on one translation unit at a time.
// 3. Linking. The linker links or "combines" all of the compiled
//		translation units into a final product (executable file,
//		library, etc).

// Two rules:
// 1. For a given function that's used somewhere in the program, that
//		function must be defined exactly once in exactly one translation
//		unit (.c file)
// 2. For a given function that's used somewhere in a given translation
//		unit, that function must be declared at least once in that
//		translation unit before it's used.

// A function prototype is a way of declaring a function without
// defining it. A function prototype must EXACTLY MATCH the header of the
// corresponding function definition.

#include "say_hello.h"

int main(void) {
	say_hello();
}
