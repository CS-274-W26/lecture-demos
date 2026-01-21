#include <stdio.h>
#include <stddef.h>

void change_me(int y) {
	y = 100;
}

void change_me_2(int* y) {
	*y = 100;
}

int main() {
	// The computer's MEMORY is just the place where it temporarily stores
	// stuff as it's operating on it. Memory is volatile. Not persistent.
	
	// The size in bytes of a variable is dictated by its type
	int x = 5;

	// change_me(x);
	change_me_2(&x);

	printf("%d\n", x); // This prints 100

	// & is the "address-of" operator. You give it a variable, and it
	// retrieves the memory address of that variable.
	printf("%p\n", &x);

	// You can store memory addresses in variables. Such variables are
	// referred to as pointers.
	int* ptr = &x;

	// Indirection: When you indirectly access a variable through a pointer
	// that points to it (indirection / dereference operator)
	*ptr = 10; // x = 10

	printf("%d\n", x);

	float* my_float_pointer = NULL;

	// if (my_float_pointer != NULL) {
	if (my_float_pointer) {
		*my_float_pointer = 5.81;
	}
	// *my_float_pointer = 5.81;

	float pi;
	my_float_pointer = &pi;

	float gravity;
	my_float_pointer = &gravity;

	*my_float_pointer = 3.14;

	my_float_pointer = &pi;

	printf("%p\n", &my_float_pointer);

	float** pointer_ception = &my_float_pointer;

	*pointer_ception = &gravity; // my_float_pointer = &gravity;
	
}
