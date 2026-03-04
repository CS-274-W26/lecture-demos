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

void free_person(const struct person* p) {
	free(p->name);
}

struct person copy_person(const struct person* p) {
	struct person deep_copy;
	deep_copy.birth_year = p->birth_year;
	deep_copy.name = malloc(sizeof(char) * (strlen(p->name) + 1));
	strcpy(deep_copy.name, p->name);
	return deep_copy;
}

void print_person(const struct person* p) {
	printf("%s was born in %d.\n", p->name, p->birth_year);
}

int main(void) {
	struct person samantha = create_person(1999, "Samantha");
	/*struct person samantha; // samantha is a structure
	samantha.birth_year = 1999; // dot operator
	samantha.name = NULL;*/
	// printf("Samantha was born in %d\n", samantha.birth_year);
	print_person(&samantha);

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
	
	/*
	struct person joseph;
	joseph.birth_year = joe->birth_year;
	joseph.name = malloc(sizeof(char) * (strlen(joe->name) + 1));
	strcpy(joseph.name, joe->name);
	*/
	struct person joseph = copy_person(joe);


	joseph.name[0] = 'L';
	printf("%s\n", joseph.name);
	printf("%s\n", joe->name);
	

	const struct person alex = {
		.birth_year = 1999,
		.name = malloc(sizeof(char) * 5)
	};

	strcpy(alex.name, "Alex");

	free_person(&alex);
	free_person(&samantha);
	free_person(&joseph);
	free_person(joe);

	free(joe);

	struct person people[12];
	for (int i = 0; i < 12; ++i) {
		people[i] = create_person(1990, "Mahatma Gandhi");
	}


	for (int i = 0; i < 12; ++i) {
		free_person(&people[i]);
	}



	typedef struct person p;


	p jim = create_person(1985, "Jim");
}
