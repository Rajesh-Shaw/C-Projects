#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

int main() {
    printf("Program started!\n");

    MYSQL *conn = connect_db();
    if (!conn) {
        printf("Failed to connect to MySQL.\n");
        return 1;
    }

    int choice, id, age;
    char name[50];

    while (1) {
        printf("\n====== Student CRUD Menu ======\n");
        printf("1. Create Student\n");
        printf("2. View Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter age: ");
                scanf("%d", &age);
                create_student(conn, name, age);
                break;

            case 2:
                read_students(conn);
                break;

            case 3:
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                getchar();
                printf("Enter new name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter new age: ");
                scanf("%d", &age);
                update_student(conn, id, name, age);
                break;

            case 4:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                delete_student(conn, id);
                break;

            case 5:
                mysql_close(conn);
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
