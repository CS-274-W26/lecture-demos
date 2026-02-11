#include <stdio.h>

void b() {
	double pi;
}

void a() {
	int y;
	b();
}

int main() {
	// Why is it hard to resize arrays?
	// Arrays are contiguous.
	_Bool z;
	int my_array[10];
	float x;

	a();

	// In the general case, in order to resize an array, you MAY need to
	// move it.
	
	// Automatic arrays can't be resized at all because they CAN'T be moved.
	
	// Automatic arrays can't be moved because they're on the stack.
	
	// The stack is the place in memory where all automatic variables
	// are stored. The stack is last-in-first-out (LIFO). Stack offsets
	// are "hardcoded" (compiled into machine instructions in executable), so
	// variables on the stack can't be moved around.
}
