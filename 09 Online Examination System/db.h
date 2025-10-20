#ifndef DB_H
#define DB_H

#include <mysql.h>

MYSQL* connect_db();
int login_user(MYSQL *conn, const char *username, const char *password, int *user_id, char *role);

#endif