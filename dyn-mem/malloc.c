#include <stdlib.h> // For malloc, free, calloc, realloc, etc.
#include <stdio.h>

int main() {
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
}
