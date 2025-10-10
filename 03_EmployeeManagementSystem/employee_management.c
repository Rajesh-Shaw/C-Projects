#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 500

struct Employee{
    int id;
    char name[50];
    int age;
    float salary;
    char department[50];
};

struct Employee employees[MAX];
int count = 0;

void addEmployee();
void displayEmployee();
void searchEmployee();
void deleteEmployee();
void saveToFile();
void loadFromFile();


int main()
{
    int choice;
    loadFromFile();

    while(1)
    {
        printf("\n=========== Employee Management System ===========\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee by ID\n");
        printf("5. Save & Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: addEmployee(); break;
            case 2: displayEmployee(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: saveToFile(); 
                    printf("Data saved. Exiting...\n");
                    exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


void addEmployee()
{
    if(count>= MAX)
    {
        printf("Employee database is full!\n");
        return;
    }

    struct Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d",&emp.id);
    getchar();

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("Enter Employee Age: ");
    scanf("%d",&emp.age);
    getchar();

    printf("Enter Employee Salary: ");
    scanf("%f",&emp.salary);
    getchar();

    printf("Enter Employee Department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = '\0';

    employees[count]=emp;
    count++;

    printf("Employee '%s' added successfully! Total Employees: %d\n", emp.name, count);

}



void displayEmployee()
{
    if(count==0)
    {
        printf("No employee records found.\n");
        return;
    }

    printf("\n--- Employee Records ---\n");
    for(int i=0; i<count; i++)
    {
        printf("ID: %d | Name: %s | Age: %d | Salary: %.2f | Department: %s\n",
               employees[i].id, employees[i].name, employees[i].age,
               employees[i].salary, employees[i].department);
    }
}

void searchEmployee()
{
    int id, found=0;
    printf("Enter Employee ID to search: ");
    scanf("%d",&id);

    for(int i=0; i<count; i++)
    {
        if(employees[i].id == id)
        {
            printf("\nEmployee Found:\n");
            printf("ID: %d | Name: %s | Age: %d | Salary: %.2f | Department: %s\n",
               employees[i].id, employees[i].name, employees[i].age,
               employees[i].salary, employees[i].department);
                
            found =1;
            break;
        }
    }

    if(!found)
        printf("No employee found with ID %d.\n", id);
}


void deleteEmployee()
{
    int id, found=0;
    printf("Enter Employee ID to delete: ");
    scanf("%d",&id);

    for(int i=0; i<count; i++)
    {
        if(employees[i].id == id)
        {
            for(int j=i; j<count-1; j++)
            {
                employees[j] = employees[j+1];
            }  
            count--;
            printf("Employee with ID %d deleted successfully.\n", id);
            found = 1;
            break;          
        }
    }

    if(!found)
        printf("No employee found with ID %d.\n", id);
}


void saveToFile()
{
    FILE *fp;
    fp = fopen("employees.txt", "w");

    if(fp == NULL)
    {
        printf("Error saving file!\n");
        return;
    }

    for(int i=0; i<count; i++)
    {
        fprintf(fp, "%d,%s,%d,%.2f,%s\n",
                employees[i].id, employees[i].name, employees[i].age,
                employees[i].salary, employees[i].department);
    }

    fclose(fp);
    printf("Employee data saved successfully.\n");
}

void loadFromFile()
{
    FILE *fp;
    fp = fopen("employees.txt", "r");

    if(fp == NULL)
    {
        printf("No previous record found.\n");
        return;
    }

    
    while(fscanf(fp, "%d,%49[^,],%d,%f,%49[^\n]\n",
                &employees[count].id, employees[count].name, &employees[count].age,
                &employees[count].salary, employees[count].department)==5)
    {
        count++;
    }

    fclose(fp);
    printf("Loaded %d employee records from file.\n", count);
}