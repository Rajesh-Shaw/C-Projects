#include <mysql.h>
#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include "db.h"
#include "admin.h"
#include "student.h"


int main()
{
    MYSQL *conn = connect_db();
    if(!conn)
    {
        printf("Database connection failed!\n");
        return 1;
    }

    int choice;
    while(1)
    {
        printf("\n===== Online Examination System =====\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); 
    

        if(choice == 1)
        {
            char username[50], password[50], role[10];
            int user_id;

            printf("Username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = '\0';
            printf("Password: ");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\n")] = '\0';

            if(login_user(conn, username, password, &user_id, role))
            {
                if(strcmp(role, "admin") == 0)
                    admin_menu(conn, user_id);
                else
                    student_menu(conn, user_id);
            }
            else
            {
                printf("Invalid username or password!\n");
            }
        }
        else if(choice == 2)
        {
            printf("Exiting... Goodbye!\n");
            mysql_close(conn);
            break;
        }
        else
        {
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}