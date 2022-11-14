#include <stdio.h>
#include <stdlib.h>
int main() {
	int age = 10;
	// pointer of type int that store
	// memory address (reference) of age
	// Note: pointer and variable
	// must be the same data type.
	int* pAge = &age;
	// Print value of age
	printf("age value = %d\n", age);
	// Print value of pAge
	printf("pAge reference address= %p\n", pAge);
	// Print memory address of age
	printf("age memory address = %p\n", &age);
	// Print value stored at memory address
	printf("pAge value stored at reference address: %d\n", *pAge);
	uint a = 1;
	printf("sizeof(uint) = %lu\n", sizeof(a));
	uint *pA = &a;
	printf("pA reference = %p\n", pA);
	return 0;
}
