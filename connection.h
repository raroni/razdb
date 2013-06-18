#include <stdio.h>

struct Connection {
  FILE *file;
  struct Database *database;
};

struct Connection *Connection_open(const char *filename, char mode);
void Connection_close(struct Connection *connection);
void Connection_write(struct Connection *connection);
void Connection_load(struct Connection *connection);