#include <iostream>

#include "greeter.hpp"

void greeter::greet() {
	std::cout << "Hello, my name is " << this->name << std::endl;
}

greeter::greeter(const std::string& n) {
	this->name = n;
}
