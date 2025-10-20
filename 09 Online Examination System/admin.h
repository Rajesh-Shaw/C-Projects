#ifndef ADMIN_H
#define ADMIN_H

#include <mysql.h>

void admin_menu(MYSQL *conn, int admin_id);
void add_question(MYSQL *conn);
void view_questions(MYSQL *conn);

#endif