#include "database.h"
#include "person.h"
#include "util.h"
#include "string.h"

void Database_initialize(struct Database *database) {
  int i = 0;
  for(i = 0; i < MAX_ROWS; i++) {
    struct Person person = { .id = 1, .set = 0 };
    database->people[i] = person;
  }
}

void Database_set(struct Database *database, int id, const char *name, const char *email) {
  struct Person *person = &database->people[id];
  if(person->set) die("Person with that ID already set. Delete it first.");

  person->set = 1;

  char *result;
  result = strncpy(person->name, name, COLUMN_LENGTH);
  if(!result) die("Name copy failed.");

  result = strncpy(person->email, email, COLUMN_LENGTH);
  if(!result) die("Email copy failed.");
}

struct Person *Database_get(struct Database *database, int id) {
  struct Person *person = &database->people[id];

  if(!person->set) die("Person not found.");
  return person;
}
