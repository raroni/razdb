#include "database.h"
#include "address.h"
#include "util.h"
#include "string.h"

void Database_initialize(struct Database *database) {
  int i = 0;
  for(i = 0; i < MAX_ROWS; i++) {
    struct Address address = { .id = 1, .set = 0 };
    database->rows[i] = address;
  }
}

void Database_set(struct Database *database, int id, const char *name, const char *email) {
  struct Address *address = &database->rows[id];
  if(address->set) die("Row already set. Delete it first.");

  address->set = 1;

  char *result;
  result = strncpy(address->name, name, COLUMN_LENGTH);
  if(!result) die("Name copy failed.");

  result = strncpy(address->email, email, COLUMN_LENGTH);
  if(!result) die("Email copy failed.");
}

struct Address *Database_get(struct Database *database, int id) {
  struct Address *address = &database->rows[id];

  if(!address->set) die("Address not found.");
  return address;
}
