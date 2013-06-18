#ifndef ADDRESS_H
#define ADDRESS_H
#define COLUMN_LENGTH 512

struct Person {
  int id;
  int set;
  char name[COLUMN_LENGTH];
  char email[COLUMN_LENGTH];
};

void Person_print(struct Person *addr);

#endif
