#include <mysql.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include "admin.h"



void admin_menu(MYSQL *conn, int admin_id)
{
    int choice;
    while (1)
    {
        printf("\n=========== Admin Panel ===========\n");
        printf("1. Add Question\n");
        printf("2. View All Questions\n");
        printf("3. Logout\n");
        printf("===================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: add_question(conn); break;
            case 2: view_questions(conn); break;
            case 3: printf("Logging out...\n"); return;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}



void add_question(MYSQL *conn)
{
    char question[500], opt1[200], opt2[200], opt3[200], opt4[200];
    int correct;

    printf("\nEnter Question: ");
    fgets(question, sizeof(question), stdin);
    question[strcspn(question, "\n")] = '\0';

    printf("Option 1: ");
    fgets(opt1, sizeof(opt1), stdin);
    opt1[strcspn(opt1, "\n")] = '\0';

    printf("Option 2: ");
    fgets(opt2, sizeof(opt2), stdin);
    opt2[strcspn(opt2, "\n")] = '\0';

    printf("Option 3: ");
    fgets(opt3, sizeof(opt3), stdin);
    opt3[strcspn(opt3, "\n")] = '\0';

    printf("Option 4: ");
    fgets(opt4, sizeof(opt4), stdin);
    opt4[strcspn(opt4, "\n")] = '\0';

    printf("Enter Correct Option (1-4): ");
    scanf("%d", &correct);
    getchar();

    char query[2000];
    snprintf(query, sizeof(query),
             "INSERT INTO questions (question_text, option1, option2, option3, option4, correct_option) "
             "VALUES ('%s', '%s', '%s', '%s', '%s', %d)",
             question, opt1, opt2, opt3, opt4, correct);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Error adding question: %s\n", mysql_error(conn));
        return;
    }
    printf("Question added successfully!\n");
}



void view_questions(MYSQL *conn)
{
    if (mysql_query(conn, "SELECT * FROM questions"))
    {
        fprintf(stderr, "Query Error: %s\n", mysql_error(conn));
        return;
    }

    MYSQL_RES *res = mysql_store_result(conn);
    MYSQL_ROW row;

    printf("\n------------------ All Questions ------------------\n");
    printf("ID\tQuestion\t\tCorrect Option\n");
    printf("---------------------------------------------------\n");
    while ((row = mysql_fetch_row(res)))
    {
        printf("%s\t%.40s...\t\t%s\n", row[0], row[1], row[6]);
    }

    mysql_free_result(res);
}