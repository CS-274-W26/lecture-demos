#include <stdlib.h> // For malloc, free, calloc, realloc, etc.
#include <stdio.h>

_Bool* create_array_of_booleans(size_t n) {
	return malloc(sizeof(_Bool) * n);
}

int main() {
	_Bool* array_of_booleans = create_array_of_booleans(100);

	float f;
	// The heap is another place in memory where variables can be stored.
	// The heap is not contiguous. It can be "fragmented".
	// The heap is NOT LIFO. Data can be freed from the heap whenever
	//		you want.
	// You HAVE to remember to free stuff from the heap.
	// Data on the heap is managed through pointers (not "hardcoded" offsets)
	
	// To allocate some memory on the heap, use malloc()
	int* ptr = malloc(sizeof(int));
	// malloc CAN fail to find a sufficiently large unallocated space. In that
	// case, it simply returns NULL.
	if (!ptr) {
		printf("Error! malloc() failed.\n");
		exit(1);
	}

	*ptr = 12;

	printf("%d\n", *ptr); // Prints 12

	// Automatic memory goes on the stack, dynamic memory goes on the heap
	// This is a dynamic array.
	int n = 50;
	double* array = malloc(sizeof(double) * n);
	array[0] = 3.14;
	array[1] = 9.81;
	
	// array[0] // Use-after free. Undefined behavior.
	
	free(ptr);

	// 1. All dynamically allocated memory must be freed exactly once
	// 2. You must not free it before you're done with it
	
	/*
	double* new_array = malloc(sizeof(double) * (n + 1));
	for (size_t i = 0; i < n; ++i) {
		new_array[i] = array[i];
	}
	free(array);
	array = new_array;
	*/

	double* another_ptr = array;


	array = realloc(array, sizeof(double) * (n + 1));

	array[n] = 3.14;
	n++;

	free(array);
	// free(new_array); // This would be a double-free. Undefined behavior.


	float* array_of_floats = calloc(1000000, sizeof(float));
}
