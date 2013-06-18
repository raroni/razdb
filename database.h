#include <stdio.h>
#include "address.h"

#define MAX_ROWS 100

struct Database {
  struct Address rows[MAX_ROWS];
};

void Database_initialize(struct Database *database);
void Database_set(struct Database *database, int id, const char *name, const char *email);
struct Address *Database_get(struct Database *database, int id);
