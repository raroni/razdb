#include <stdio.h>
#include "person.h"

#define MAX_ROWS 100

struct Database {
  struct Person people[MAX_ROWS];
};

void Database_initialize(struct Database *database);
void Database_set(struct Database *database, int id, const char *name, const char *email);
struct Person *Database_get(struct Database *database, int id);
