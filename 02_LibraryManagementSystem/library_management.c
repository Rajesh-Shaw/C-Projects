#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

struct Book{
    int id;
    char title[100];
    char author[50];
    float price;
};

int count=0;
struct Book books[MAX];

void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void saveToFile();
void loadFromFile();

int main()
{
    int choice=0;
    loadFromFile();

    while(1)
    {
        printf("\n============= Library Management System ==================\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Save & Exit\n\n");

        printf("Enter Your choice: ");
        scanf("%d",&choice);


        switch(choice)
        {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: saveToFile(); printf("Exiting Program! Goodbye :)\n"); exit(0);
            default: printf("Invalid Choice! Please Enter a Correct Choice.");
        }
    }

    return 0;
}



void addBook()
{
    if (count >= MAX) 
    {
        printf("Book storage full! Cannot add more books.\n");
        return;
    }

    struct Book B;
    printf("Enter Book ID: ");
    scanf("%d",&B.id);
    getchar(); // clear newline

    printf("Enter Book Title: ");
    fgets(B.title, sizeof(B.title), stdin);
    B.title[strcspn(B.title, "\n")] = '\0'; // remove newline
    
    printf("Enter Book Author Name: ");
    fgets(B.author, sizeof(B.author), stdin);
    B.author[strcspn(B.author, "\n")] = '\0'; // remove newline

    printf("Enter Book Price: ");
    scanf("%f",&B.price);

    books[count++] = B;
    printf("Successfully Added the Book '%s by %s'.",B.title, B.author);

}
void displayBooks()
{
    if(count==0)
    {
        printf("No Books in the System.");
        return;
    }

    printf("\n--- Books in the Library ---\n");
    for(int i=0; i<count; i++)
    {
        printf("ID: %d | Title: %s | Author: %s | Price: %.2f\n", books[i].id, books[i].title, books[i].author, books[i].price);
    }

}

void searchBook()
{
    int id,found=0;
    if(count==0)
    {
        printf("No Books in the System.");
        return;
    }

    printf("Enter Book ID to search: ");
    scanf("%d",&id);

    for(int i=0; i<count; i++)
    {
        if(books[i].id==id)
        {
            printf("\nBook Found!\n");
            printf("ID: %d | Title: %s | Author: %s | Price: %.2f\n",
               books[i].id, books[i].title, books[i].author, books[i].price);

            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("No book found with ID %d.\n", id);
    }

}

void deleteBook()
{
    int id,found=0;
    if(count==0)
    {
        printf("No Books in the System.");
        return;
    }

    printf("Enter Book ID to delete: ");
    scanf("%d",&id);

    for(int i=0; i<count; i++)
    {
        if(books[i].id==id)
        {
            for(int j=i; j<count-1; j++)
            {
                books[j] = books[j+1];
            }
            count--;
            printf("Successfully deleted book with ID %d.\n",id);
            found =1;
            break;
        }
    }

    if(!found)
    {
        printf("No book found with ID %d.\n", id);
    }

}

void saveToFile()
{
    FILE *fp = fopen("books.txt", "w");
    if(fp == NULL)
    {
        printf("Error saving file!\n");
        return;
    }

    for(int i=0; i<count; i++)
    {
        fprintf(fp, "%d,%s,%s,%.2f\n",books[i].id, books[i].title, books[i].author, books[i].price);
    }

    fclose(fp);
    printf("Data saved to 'books.txt' successfully.\n");

}

void loadFromFile()
{
    FILE *fp = fopen("books.txt", "r");
    if(fp == NULL)
    { 
        printf("File not existing.\n");
        return; 
    }

    while(fscanf(fp, "%d,%99[^,],%49[^,],%f\n", &books[count].id, books[count].title, books[count].author, &books[count].price) == 4)
    {
        count++;
    }

    fclose(fp);
    printf("Loaded %d books from file.\n", count);
}