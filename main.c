#include <stdlib.h>
#include "database.h"
#include "person.h"
#include "connection.h"
#include "util.h"

int main(int argc, char *argv[]) {
  if(argc < 3) die("USAGE app <dbfile> <action>");

  char *filename = argv[1];
  char action = argv[2][0];

  struct Connection *connection;
  connection = Connection_open(filename, action);

  int id = 0;
  if(argc > 3) id = atoi(argv[3]);

  switch(action) {
    case 'c':
      Database_initialize(connection->database);
      Connection_write(connection);
      printf("Database created.\n");
      break;
    case 's':
      if(argc != 6) die("Need id, name, email to set.");
      Database_set(connection->database, id, argv[4], argv[5]);
      Connection_write(connection);

      printf("Person %d created.\n", id);
      break;
    case 'g':
      if(!id) die("Need an ID to get.");
      struct Person *person = Database_get(connection->database, id);
      Person_print(person);
      break;
    default:
      die("Invalid action.");
  }

  Connection_close(connection);

  return 0;
}
