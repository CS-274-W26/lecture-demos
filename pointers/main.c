#include <stdio.h>
#include <stddef.h>

void change_me(int y) {
	y = 100;
}

void change_me_2(int* y) {
	*y = 100;
}

float* create_5() {
	float five = 5.0;
	
	// Creates dangling pointer. Likely to lead to undefined behavior. Very
	// bad idea. GCC will warn you.
	return &five;
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

		float eulers_constant = 2.71;
		my_float_pointer = &eulers_constant;
	}

	// What's wrong with this?
	// Dangling pointer. Use-after-free.
	// printf("%f\n", *my_float_pointer);
	
	// Another dangling pointer
	// float* five_ptr = create_5();
	

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

	// The stack is a special place in memory where automatic variables
	// are stored.
	
	// Everything on the stack is freed automatically when it falls out
	// of scope.
	
	// Constness w.r.t. pointers
	const float eulers_constant = 2.71;

	// You can create pointers that themselves are constant
	// You can also create pointers whose underlying values cannot
	// 	be modified THROUGH the pointer / indirection
	
	// Non-contant pointer to constant data
	int const * pointer_to_const = &x;
	*pointer_to_const = 99; // This is a syntax error!
	x = 99; // This is fine
	int y;
	pointer_to_const = &y; // This is fine
	*pointer_to_const = 10; // This is a syntax error!

	// Constant pointer to non-constant data
	int* const const_pointer = &x;
	const_pointer = &y; // This is a syntax error!
	*const_pointer = 100; // This is fine

	// Constant pointer to constant data
	int const * const const_pointer_to_const = &x;
	const_pointer_to_const = &y; // This is a syntax error!
	*const_pointer_to_const = 101; // This is also a syntax error!
}
