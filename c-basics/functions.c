#include <stdio.h>

double volume_of_sphere(double radius) {
	// This is the actual code that the function executes
	double volume = 4.0 / 3.0 * 3.141592 * radius * radius * radius;

	return volume; // Return statements end the function
}

void count(int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d\n", i + 1);
	}
}

int main() {
	printf("What is the radius of your sphere?: ");
	double r;
	scanf("%f", &r);

	double v = volume_of_sphere(r);

	// The main function is special. If it doesn't return anything
	// it automatically and implicitly returns 0
	
	// The return value of the main function indicates the process's
	// exit code. The convention is that an exit value of 0 means
	// "I terminated normally". Nonzero exit codes mean that the program
	// exited suddenly because it couldn't run to completion.
	
	return 0;
}
