#include <stdlib.h>
#include <stdio.h>
#pragma pack(1)
// Conventional typedef
// typedef <struct Alias {..}> Alias;
// Note: Use same Alias_name for convenience
typedef struct Person {
	int  id;
	int  age;
	char name[10];
} Person;

void display(Person p);

struct user {
	int id;
	char name[10];
};

struct user const users[3] = {
	{1, "USER_1"},
	{2, "USER_2"},
	{3, "USER_3"}
};

int main() {
	Person person1 = {1, 31, "Amine"};
	display(person1);	
	for(int i = 0; i < (sizeof(users)/sizeof(users[1])); i++) {
		printf("USER[%d] :\nID#%d\nName: %s\n", i, users[i].id, users[i].name);
	}
	printf("Size of users: %lu\n", sizeof(users));
	int a = 1, b = 1;
	printf("%d", a++ + ++b);
	return EXIT_SUCCESS;
}

void display(Person p) {
	printf("ID: %d\nAge: %d\nName: %s\n", p.id, p.age, p.name);
}
