#ifndef DB_H
#define DB_H

#include <mysql.h>

// Function declarations
MYSQL* connect_db();
void create_student(MYSQL *conn, const char *name, int age);
void read_students(MYSQL *conn);
void update_student(MYSQL *conn, int id, const char *name, int age);
void delete_student(MYSQL *conn, int id);

#endif
