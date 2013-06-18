#ifndef ADDRESS_H
#define ADDRESS_H
#define COLUMN_LENGTH 512

struct Address {
  int id;
  int set;
  char name[COLUMN_LENGTH];
  char email[COLUMN_LENGTH];
};

void Address_print(struct Address *addr);

#endif
