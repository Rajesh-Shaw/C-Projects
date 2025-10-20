#ifndef STUDENT_H
#define STUDENT_H

#include <mysql.h>

void student_menu(MYSQL *conn, int student_id);
void take_exam(MYSQL *conn, int student_id);
void view_results(MYSQL *conn, int student_id);

#endif