#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db.h"



#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "root"  
#define DB_NAME "exam_db"

MYSQL* connect_db() 
{
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) 
    {
        fprintf(stderr, "mysql_init() failed\n");
        return NULL;
    }

    if (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0) == NULL) 
    {
        fprintf(stderr, "Connection error: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    printf("Connected to MySQL database!\n");
    return conn;
}

int login_user(MYSQL *conn, const char *username, const char *password, int *user_id, char *role)
{
    char query[256];
    snprintf(query, sizeof(query),
             "SELECT user_id, role FROM users WHERE username='%s' AND password='%s'",
             username, password);
    
    if (mysql_query(conn, query)) 
    {
        fprintf(stderr, "Query error: %s\n", mysql_error(conn));
        return 0;
    }
    
    MYSQL_RES *res = mysql_store_result(conn);
    if (!res) return 0;

    MYSQL_ROW row = mysql_fetch_row(res);
    if (row) 
    {
        *user_id = atoi(row[0]);
        strcpy(role, row[1]);
        mysql_free_result(res);
        return 1;
    }
    mysql_free_result(res);
    return 0;
}