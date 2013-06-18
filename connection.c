#include <stdlib.h>
#include "connection.h"
#include "database.h"
#include "util.h"

struct Connection *Connection_open(const char *filename, char mode)
{
  struct Connection *connection = malloc(sizeof(struct Connection));
  if(!connection) die("Could not allocate memory for connection.");

  connection->database = malloc(sizeof(struct Database));
  if(!connection) die("Could not allocate memory for database.");

  if(mode == 'c') {
    connection->file = fopen(filename, "w");
    if(!connection->file) die("Could not create file.");
  } else {
    connection->file = fopen(filename, "r+");
    if(!connection->file) die("Could not open file.");
    Connection_load(connection);
  }

  return connection;
}

void Connection_close(struct Connection *connection) {
  fclose(connection->file);
  free(connection->database);
  free(connection);
}

void Connection_write(struct Connection *connection) {
  int result;

  rewind(connection->file);
  result = fwrite(connection->database, sizeof(struct Database), 1, connection->file);
  if(result != 1) die("Write failed.");
  
  result = fflush(connection->file);
  if(result == -1) die("File flush failed.");
}

void Connection_load(struct Connection *connection) {
  int result;
  result = fread(connection->database, sizeof(struct Database), 1, connection->file);
  if(result != 1) die("Failed to load database from disk.");
}
