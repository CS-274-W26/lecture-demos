#include <stdio.h>

int main() {
	// An array is a contiguous, homogeneous, fixed-size sequence of
	// elements.
	//
	// Contiguous: Everything is right next to each other in memory
	// Homogeneous: Everything in the array is of the same type
	// Fixed-size: An array's size cannot be changed.
	// Sequence: Every element has an integer position.
	// Element: Something in an array
	
	// When you create an array in C, the size SHOULD be a compile-time
	// constant.
	
	// Here's how you create a regular, automatic array.
	// In the array initializer, any missing elements are zero-initialized.
	int my_cool_numbers[7] = {1, 7, 9, -4, 2};

	char empty_string[1000] = {'\0'};
	empty_string[0] = 'H';
	empty_string[1] = 'e';
	empty_string[2] = 'l';
	empty_string[3] = 'l';
	empty_string[4] = 'o';

	// You can't do this
	// my_cool_numbers = {1, 4, 8, 2, 1, 3, 4};

	// How to access one of those elements
	// C arrays use zero-based indexing.
	my_cool_numbers[2] = 72;

	printf("%d\n", my_cool_numbers[0]);

	// In MOST contexts, arrays decay into their base addresses
	printf("%p\n", my_cool_numbers);

	int* ptr = my_cool_numbers;
	printf("%p\n", ptr);

	// If you have a pointer that points to the beginning of an
	// array, you can use that pointer AS IF it were the array itself.
	ptr[1]++;

	printf("%d\n", my_cool_numbers[1]); // Prints 8

	ptr = &(my_cool_numbers[2]);
	printf("%d\n", ptr[0]); // This prints the third element of the array
}
