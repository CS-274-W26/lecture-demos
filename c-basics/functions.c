#include <math.h>
#include <stdio.h>

// Function prototype. Declaration, but NOT a definition
double volume_of_sphere(double radius);

void some_other_function() {
	volume_of_sphere(3.1f);
}


// A function definition AND declaration
double volume_of_sphere(double radius) {
	// This is the actual code that the function executes
	double volume = 4.0 / 3.0 * 3.141592 * pow(radius, 3);

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
	scanf("%lf", &r);

	double v = volume_of_sphere(r);

	// The main function is special. If it doesn't return anything
	// it automatically and implicitly returns 0
	
	// The return value of the main function indicates the process's
	// exit code. The convention is that an exit value of 0 means
	// "I terminated normally". Nonzero exit codes mean that the program
	// exited suddenly because it couldn't run to completion.
	
	printf("%lf\n", v);

	return 0;
}
