#include <stdio.h> // Preprocessing directive
#include <math.h> // pow()

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
	
	// Operators
	// +: Addition
	// -: Subtraction
	// *: Multiplication
	// /: Division
	// %: Modulo
	//
	// There is no exponential operator in C
	// pow(2, 5) 
	printf("5 * 7 / 2 + 4 = %d\n", 5 * 7 / 2 + 4);

	// In C, the division operator when used on two integers will produce
	// an integer. The rule is truncation. Rounding toward zero.
	// Slicing off the would-be decimal point and everything after it.
	//
	
	// To create a variable in C, you must DECLARE it.
	// type name; // Variable declaration
	
	// When you declare a variable in C, you state its type, and after that,
	// its type can NEVER change.
	int x; // Variable declaration

	// To initialize a variable, use the assignment operator
	x = 5 * 7 / 2 + 4;

	// The type of expression on the right must be "compatible with"
	// the type of variable on the left

	// When a variable is declared but NOT initialized, its value is
	// undefined / uninitialized / garbage. To use an undefined /
	// uninitialized / garbage variable is undefined behavior.
	printf("%d\n", x);

	// Implicit type casting / type coercion. This can happen any time
	// the compiler expects an expression of one type but you provide
	// an expression of a different, but compatible, type.
	
	// The conversion rules:
	// If you're casting a float or double to an int or long int,
	// the conversion rule is truncation.
	// If you're casting an int or long int to a float or double,
	// the conversion rule is to just tack on a .0.
	
	x = 3.14;

	printf("%d\n", x); // Prints 3

	double pi = 3;

	// % only works between two integral values
	

	// There are no booleans in C
	
	// x is specifically an "automatic variable".
	// x has automatic storage duration.
	//
	

	int y = 5;



	// Explicit type casting is where you explicitly / intentionally
	// convert an expression of one type to a new expression of another
	// (compatible) type
	printf("%f\n", (double) x / y);
	
	// When you declare a constant, you MUST initialize it at the same time.
	const double GRAVITY = 9.81;

	// After the declaration of a constant, its value cannot be changed
	// GRAVITY = 10.5; // This is a syntax error!
	
	// Standard input. In practice, scanf() is very hard to use correctly.
	// The only time you should use scanf is when you REALLY trust the
	// user to provide values that are appropriate.
	printf("Please type in your two favorite numbers: ");

	float my_float, my_float2;
	scanf("%f %f", &my_float, &my_float2);

	// Relational operators in C:
	// >, >=, <, <=, ==, !=
	
	// Logical operators in C:
	// || (logical or, with short circuiting)
	// && (logical and, with short circuiting)
	// ! (not)
	//
	// Technically, there's also
	// | (logical or, without short circuiting)
	// & (logical and, without short circuiting)
	
	x = 7;

	if (x >= 5 && x <= 10) {
		// As much code here as you want
		printf("Hello!\n");
	} else if (x >= 12 && x <= 14) {
		// As much code here as you want
	} else {
		// As much code here as you want

		// Nested scope. A scope inside another scope.
		printf("%d\n", x);

		int z;
		printf("%d\n", z);
		// You can redeclare symbols in nested scopes
		// This is called shadowing.
		int x = 12;

		printf("%d\n", x); // This prints 12
	}
	// The old x becomes "unshadowed" when the else block ends.

	printf("%d\n", x); // This prints 7
	// printf("%d\n", z); // Syntax error

	// Scopes in C are loosely dictated by curly braces.
	// A scope dictates two things:
	// 1. Where symbols are accessible
	// 	Symbols are accessible only within their scopes below their
	// 	point of declaration.
	// 2. When automatic variables are freed from memory
	// 	When a variable's scope ends, the computer is then allowed
	// 	to free that variable from memory.
	
	// an automatic variable is a regular, function-local variable.
	// Automatic variables have automatic storage duration.
	
	// C has three kinds of loops:
	// while
	// do-while
	// for
	
	int counter = 0;
	while (counter < 10) {
		printf("Hello\n");
		counter = counter + 1;
	}

	counter = 0;
	do {
		printf("Hello\n");
		counter = counter + 1;
	} while(counter < 10);


	// For loop headers have three things in them:
	// 1. Initialization statement
	// 2. Condition
	// 3. Post statement
	for (int i = 0; i < 10; i = i + 1) {
		printf("Hello %d\n", i);
	}

	// Shorthand operators
	// +=, -=, *=, /=, %=
	int variable = 0;
	variable += 7;

	// ++
	// --
	variable++; // Post-increment
	++variable; // Pre-increment

	variable--; // Post-decrement
	--variable; // Pre-decrement
	
	// printf("%d\n", variable++);
	printf("%d\n", ++variable);
}


