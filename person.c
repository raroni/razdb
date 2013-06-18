#include <stdio.h>
#include "person.h"

void Person_print(struct Person *person) {
  printf("ID: %d\n", person->id);
  printf("Name: %s\n", person->name);
  printf("Email: %s\n", person->email);
}
