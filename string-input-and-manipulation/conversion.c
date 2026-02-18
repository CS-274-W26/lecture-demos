#include <stdlib.h>
#include <stdio.h>

int main() {
	char* endptr = NULL;

	const char* my_string = "3.1j4";
	double my_double = strtod(my_string, &endptr);
	printf("%lf\n", my_double);

	// my_double now stores 3.1, and endptr stores the address of the
	// 'j' character after the 3.1 in my_string
	printf("%c\n", *endptr);

	endptr = NULL;
	const char* my_string2 = "1000000000";
	long my_long = strtol(my_string2, &endptr, 10);
}
