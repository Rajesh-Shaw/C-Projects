#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include "db.h"

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "root"      // change if needed
#define DB_NAME "student_db" // make sure this DB exists

// ✅ Connect to MySQL
MYSQL* connect_db() {
    MYSQL *conn = mysql_init(NULL);
    if (!conn) {
        fprintf(stderr, "mysql_init() failed\n");
        return NULL;
    }

    // Disable SSL to avoid “unknown error number” issue
    mysql_options(conn, MYSQL_OPT_SSL_MODE, (void *)0);

    printf("Connecting to MySQL...\n");
    if (!mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0)) {
        fprintf(stderr, "Connection failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    printf("Connected to MySQL database '%s' successfully!\n", DB_NAME);
    return conn;
}

// ✅ CREATE
void create_student(MYSQL *conn, const char *name, int age) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO students (name, age) VALUES ('%s', %d)", name, age);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Insert error: %s\n", mysql_error(conn));
        return;
    }
    printf("Student '%s' (Age: %d) added successfully!\n", name, age);
}

// ✅ READ
void read_students(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM students")) {
        fprintf(stderr, "Query error: %s\n", mysql_error(conn));
        return;
    }

    MYSQL_RES *res = mysql_store_result(conn);
    if (!res) {
        fprintf(stderr, "Failed to retrieve result set: %s\n", mysql_error(conn));
        return;
    }

    MYSQL_ROW row;
    printf("\n📋 Student List:\n");
    printf("----------------------------------\n");
    printf("ID\tName\t\tAge\n");
    printf("----------------------------------\n");

    while ((row = mysql_fetch_row(res))) {
        printf("%s\t%-15s\t%s\n", row[0], row[1], row[2]);
    }

    printf("----------------------------------\n");
    mysql_free_result(res);
}

// ✅ UPDATE
void update_student(MYSQL *conn, int id, const char *name, int age) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE students SET name='%s', age=%d WHERE id=%d", name, age, id);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Update error: %s\n", mysql_error(conn));
        return;
    }

    if (mysql_affected_rows(conn) > 0)
        printf("Student ID %d updated successfully!\n", id);
    else
        printf("No student found with ID %d.\n", id);
}

// ✅ DELETE
void delete_student(MYSQL *conn, int id) {
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM students WHERE id=%d", id);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Delete error: %s\n", mysql_error(conn));
        return;
    }

    if (mysql_affected_rows(conn) > 0)
        printf("Student ID %d deleted successfully!\n", id);
    else
        printf("No student found with ID %d.\n", id);
}
