#include <iostream>
#include <string>

int main() {
	std::string message = "Hello, World!\n";

	std::cout << message;

	int x;
	int* p = &x;
	*p = 5;

	std::cout << x << std::endl; // Prints 5

	// References are loosely just pointers with simpler syntax
	// References are always constant in and of themselves.
	// References must be initialized the moment they're declared.
	// References use & instead of a * in their declaration.
	int& r = x; // r now refers to x
	
	r = 5; // x = 5

	int y = 7;
	r = y; // x = y


}
