#ifndef GREETER_HPP
#define GREETER_HPP

#include <string>

class greeter {
private:
	std::string name; // Field, attribute, member variable
public:
	greeter(const std::string& n);
	void greet(); // Method prototype
};

#endif
