#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void bubble_sort(int* array, size_t size, _Bool (*should_swap)(int, int)) {
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t j = 0; j < size - 1 - i; ++j) {
			// Check if the jth element should be swapped with
			// the j+1st element
			if ((*should_swap)(array[j], array[j+1])) {
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

_Bool should_swap_ascending(int a, int b) {
	return a > b;
}

_Bool should_swap_descending(int a, int b) {
	return a < b;
}

_Bool should_swap_ascending_magnitudes(int a, int b) {
	return abs(a) > abs(b);
}

float foo(double a, char* b) {
	printf("%s\n", b);
	return a / 2.0;
}

int main(void) {
	// Function pointers are pointers that point to functions
	float (*p)(double, char*);

	// This is the explicit syntax
	p = &foo;

	// An implicit syntax:
	p = foo;

	// Explicit calling syntax
	float result = (*p)(3.14, "Hello");
	printf("%f\n", result);

	// Implicit calling syntax
	result = p(3.14, "Hello");
	printf("%f\n", result);

	int array[5] = {1, -4, 12, 2, 19};
	bubble_sort(array, 5, should_swap_ascending);

	for (size_t i = 0; i < 5; ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");

	bubble_sort(array, 5, should_swap_descending);

	for (size_t i = 0; i < 5; ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");

	bubble_sort(array, 5, should_swap_ascending_magnitudes);

	for (size_t i = 0; i < 5; ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");
}
