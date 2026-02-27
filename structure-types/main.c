#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Rules for structure types:
// 1. For a given structure type that's used in a given translation unit,
//	that structure type must be DEFINED EXACTLY ONCE in that translation unit before it
//	can be used. Every translation unit that uses the structure type must
//	have the EXACT SAME definition for it (token-for-token).

#include "person.h"

// When you return a structure from a function, it MIGHT copy that entire
// structure, but actually, in most cases, the compiler can avoid that.
struct person create_person(int birth_year, const char* name) {
	struct person result;
	result.birth_year = birth_year;
	result.name = malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(result.name, name);
	return result;
}

int main(void) {
	struct person samantha; // samantha is a structure
	samantha.birth_year = 1999; // dot operator
	samantha.name = NULL;
	printf("Samantha was born in %d\n", samantha.birth_year);

	struct person* ptr = &samantha;
	printf("%p\n", ptr);
	
	(*ptr).birth_year = 1998;
	ptr->birth_year = 1998;

	struct person* joe = malloc(sizeof(struct person));

	joe->birth_year = 2025;
	joe->name = malloc(sizeof(char) * 4);
	strcpy(joe->name, "Joe");




	// The assignment operator when placed between two structures simply
	// copies each of the fields from the structure on the right into the
	// corresponding fields of the structure on the left, one at a time,
	// as if using the assignment operator on them.
	// struct person joseph = *joe;

	// = on structures performs a shallow copy
	
	// struct person joseph;
	// joseph.birth_year = joe->birth_year;
	// joseph.name = joe->name;
	
	// The alternative is a deep copy. In C, deep copies must be facilitated
	// manually.
	
	struct person joseph;
	joseph.birth_year = joe->birth_year;
	joseph.name = malloc(sizeof(char) * (strlen(joe->name) + 1));
	strcpy(joseph.name, joe->name);
	joseph.name[0] = 'L';
	printf("%s\n", joseph.name);
	printf("%s\n", joe->name);
	

	const struct person alex = {
		.birth_year = 1999,
		.name = malloc(sizeof(char) * 5)
	};

	strcpy(alex.name, "Alex");

	free(joe);
}
