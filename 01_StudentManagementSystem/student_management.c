#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Student{
    int id;
    char name[50];
    int age;
    float marks;
};

struct Student students[MAX];
int count=0;

void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();

int main()
{
    int choice;

    while(1)
    {
        printf("\n===================================\n");
        printf("      Student Management System \n");
        printf("===================================\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting Program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }

    }

    return 0;
}


void addStudent()
{
    if(count == MAX)
    {
        printf("Database full! Cannot add more students.\n");
        return;
    }

    struct Student s;

    printf("Enter Student ID: ");
    scanf("%d",&s.id);
    printf("Enter Name: ");
    getchar(); // clear newline from buffer
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[count++]=s;
    printf("Student added successfully!\n");
}


void displayStudents()
{
    if(count == 0)
    {
        printf("No Student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for(int i=0; i<count; i++)
    {
        printf("ID: %d | Name: %s | Age: %d | Marks: %.2f\n",
       students[i].id, students[i].name, students[i].age, students[i].marks);
    }
}


void searchStudent()
{
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++)
    {
        if(students[i].id == id)
        {
            printf("\nRecord Found!\n");
            printf("ID: %d | Name: %s | Age: %d | Marks: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No Student found with ID %d.\n", id);
}



void deleteStudent() 
{
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) 
    {
        if (students[i].id == id) 
        {
            for (int j = i; j < count - 1; j++) 
            {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student with ID %d deleted successfully.\n", id);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No student found with ID %d.\n", id);
}
