#include <stdio.h>

// If the argument points to an int, type_code should be 0.
// If it points to a float, type_code should be 1.
// If it points to a double, type_code should be 2.
void print_value(void* argument, int type_code) {
	if (type_code == 0) {
		// argument points to an integer
		printf("%d\n", *((int*) argument));
	} else if (type_code == 1) {
		// argument points to a float
		printf("%f\n", *((float*) argument));
	} else if (type_code == 2) {
		// argument points to a double
		printf("%lf\n", *((double*) argument));
	}
}

int main(void) {
	int x;
	int y;
	double z = 3.14;
	// int* p = &z;

	// A void pointer is simply a pointer that can point to (almost) anything
	void* p = &z;

	// Void pointers are incredibly limited.
	// 1. You CANNOT dereference a void pointer. *. []. ->
	// 2. You also technically CANNOT do pointer arithmetic on a void pointer.
	//		* GCC has an extension that treats void* as char* for the purposes
	//			of pointer arithmetic
	
	// The main things you CAN do with void pointers are:
	// 1. Cast them BACK to their original pointer type
	// 2. Pass them around to functions
	
	double* p2 = (double*) p;

	// printf("%.2lf\n", *p2);

	print_value(&z, 2);
}
