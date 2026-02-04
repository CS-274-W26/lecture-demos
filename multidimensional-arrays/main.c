#include <stdio.h>

void print_matrix(float my_matrix[][3], size_t n_rows) {
	for (int i = 0; i < n_rows; ++i) {
		// Print the ith row
		for (int j = 0; j < 3; ++j) {
			// Print the jth element of the ith row
			printf("%f\t", my_matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	// A 2D array is, very loosely, an array of arrays
	
	// A 2D array is like a table / matrix
	
	// Today, we're going to focus on contiguous multidimensional
	// stack-allocated (automatic) arrays
	
	// A regular 1D array is contiguous in memory
	
	float my_matrix[][3] = {
		{3.14, 9.81, 2.71},
		{-7.5, 1.2}
	};
	// float my_matrix[2][3] = {{0.0}}; // Zero-initialization

	printf("%p\n", my_matrix[1]);
	printf("%p\n", &(my_matrix[1][0]));

	print_matrix(my_matrix, 2);

	int my_array[5] = {0};

	// The stride of a dimension of a contiguous multidimensional array
	// is the number of bytes between adjacent elements along that
	// dimension
	//
	// my_array[i][j],    my_array[i+1][j]
	// my_array[i][j],    my_array[i][j+1]


	// EVERYTHING BELOW WILL NOT BE ON THE MIDTERM
	
	// A non-contiguous 2D array is an array of pointers,
	// where each pointer points to a 1D array
	
	int row1[] = {1, 7, -2};
	_Bool i_like_pizza;
	int row2[] = {-1, 5};
	int row3[] = {15, 70, 2};
	int* array_of_pointers[] = {row1, row2, row3};
}
