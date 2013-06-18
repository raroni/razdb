#include <stdio.h>
#include "address.h"

void Address_print(struct Address *address) {
  printf("ID: %d\n", address->id);
  printf("Name: %s\n", address->name);
  printf("Email: %s\n", address->email);
}
