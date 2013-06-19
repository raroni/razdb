#ifndef PERSON_H
#define PERSON_H
#define COLUMN_LENGTH 512

struct Person {
  int id;
  int set;
  char name[COLUMN_LENGTH];
  char email[COLUMN_LENGTH];
};

void Person_print(struct Person *addr);

#endif
