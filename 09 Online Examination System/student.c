#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"



void student_menu(MYSQL *conn, int student_id)
{
    int choice;
    while (1)
    {
        printf("\n=========== Student Panel ===========\n");
        printf("1. Take Exam\n");
        printf("2. View Results\n");
        printf("3. Logout\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: take_exam(conn, student_id); break;
            case 2: view_results(conn, student_id); break;
            case 3: printf("Logging out...\n"); return;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}


void take_exam(MYSQL *conn, int student_id)
{
    if (mysql_query(conn, "SELECT * FROM questions"))
    {
        fprintf(stderr, "Query Error: %s\n", mysql_error(conn));
        return;
    }

    MYSQL_RES *res = mysql_store_result(conn);
    MYSQL_ROW row;

    int total = mysql_num_rows(res);
    int score = 0;
    int qno = 1;

    while ((row = mysql_fetch_row(res)))
    {
        printf("\nQ%d: %s\n", qno++, row[1]);
        printf("1. %s\n", row[2]);
        printf("2. %s\n", row[3]);
        printf("3. %s\n", row[4]);
        printf("4. %s\n", row[5]);

        int ans;
        printf("Your answer: ");
        scanf("%d", &ans);
        getchar();

        int correct = atoi(row[6]);
        if (ans == correct)
            score++;
    }
    mysql_free_result(res);

    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO results (user_id, score, total) VALUES (%d, %d, %d)",
             student_id, score, total);
    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Error saving result: %s\n", mysql_error(conn));
        return;
    }

    printf("\nExam Completed! Your Score: %d/%d\n", score, total);
}




void view_results(MYSQL *conn, int student_id)
{
    char query[256];
    snprintf(query, sizeof(query),
             "SELECT score, total, taken_on FROM results WHERE user_id=%d ORDER BY taken_on DESC",
             student_id);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Query Error: %s\n", mysql_error(conn));
        return;
    }

    MYSQL_RES *res = mysql_store_result(conn);
    MYSQL_ROW row;

    printf("\n-------------- Exam Results --------------\n");
    printf("Score\tTotal\tDate\n");
    printf("------------------------------------------\n");

    while ((row = mysql_fetch_row(res)))
    {
        printf("%s\t%s\t%s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(res);
}

