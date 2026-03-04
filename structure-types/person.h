#ifndef PERSON_H
#define PERSON_H

// 1. Function prototypes
// 2. Structure type definitions

// A structure type is like a class, except it can only have fields (members).
// You can't have methods / member functions in a structure type in C.
// There's no inheritance in C.
struct person {
	int birth_year;
	char* name;
}; // <- mind the semicolon

/*
struct person {
	int birth_year;
	char name[1024];
}; // <- mind the semicolon
*/

#endif
