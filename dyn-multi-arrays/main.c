#include <stdlib.h>
#include <stdio.h>

void populate(int** table, size_t rows, size_t columns) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			table[i][j] = (i + 1) * (j + 1);
		}
	}
}

void print_table(int** table, size_t rows, size_t columns) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
}

int main() {
	// int matrix[10][12] = {0};
	// matrix[1][2] = 0;

	size_t n_rows = 10;
	size_t n_columns = 12;

	// There's another "noncontiguous" way of storing multidimensional
	// arrays in memory
	int** array = malloc(sizeof(int*) * n_rows);
	for (size_t i = 0; i < n_rows; ++i) {
		array[i] = malloc(sizeof(int) * n_columns);
	}

	// array[1][2] = 0;

	populate(array, n_rows, n_columns);
	print_table(array, n_rows, n_columns);

	for (size_t i = 0; i < n_rows; ++i) {
		free(array[i]);
	}
	free(array);
}
