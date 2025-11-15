#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.dat"

typedef struct {
    int id;
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function prototypes
void add_contact();
void view_contacts();
void search_contact();
void update_contact();
void delete_contact();
void sort_contacts();
int get_new_id();



int main() 
{
    int choice;

    while (1) 
    {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Sort Contacts (A-Z)\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: add_contact(); break;
            case 2: view_contacts(); break;
            case 3: search_contact(); break;
            case 4: update_contact(); break;
            case 5: delete_contact(); break;
            case 6: sort_contacts(); break;
            case 7: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}




int get_new_id() 
{
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 1;

    Contact c;
    int max_id = 0;

    while (fread(&c, sizeof(Contact), 1, fp))
        if (c.id > max_id)
            max_id = c.id;

    fclose(fp);
    return max_id + 1;
}






void add_contact() 
{
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) { printf("Error opening file!\n"); return; }

    Contact c;
    c.id = get_new_id();

    printf("Enter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0;

    printf("Enter Phone: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    fwrite(&c, sizeof(Contact), 1, fp);
    fclose(fp);

    printf("Contact added successfully!\n");
}




void view_contacts() 
{
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) { printf("No contacts found.\n"); return; }

    Contact c;
    printf("\nID\tName\t\tPhone\t\tEmail\n");
    printf("-----------------------------------------------------------\n");

    while (fread(&c, sizeof(Contact), 1, fp)) {
        printf("%d\t%-15s\t%-12s\t%s\n", c.id, c.name, c.phone, c.email);
    }

    fclose(fp);
}




void search_contact() 
{
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) { printf("No contacts found.\n"); return; }

    char key[50];
    printf("Enter name or phone to search: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    Contact c;
    int found = 0;

    while (fread(&c, sizeof(Contact), 1, fp)) {
        if (strstr(c.name, key) || strstr(c.phone, key)) {
            printf("\nFound Contact:\n");
            printf("ID: %d\nName: %s\nPhone: %s\nEmail: %s\n",
                   c.id, c.name, c.phone, c.email);
            found = 1;
        }
    }

    if (!found) printf("No matching contact found.\n");

    fclose(fp);
}




void update_contact() 
{
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) { printf("No contacts available.\n"); return; }

    int id;
    printf("Enter Contact ID to update: ");
    scanf("%d", &id);
    getchar();

    Contact c;
    int found = 0;

    while (fread(&c, sizeof(Contact), 1, fp)) 
    {
        if (c.id == id) {
            found = 1;

            printf("Enter new Name: ");
            fgets(c.name, sizeof(c.name), stdin);
            c.name[strcspn(c.name, "\n")] = 0;

            printf("Enter new Phone: ");
            fgets(c.phone, sizeof(c.phone), stdin);
            c.phone[strcspn(c.phone, "\n")] = 0;

            printf("Enter new Email: ");
            fgets(c.email, sizeof(c.email), stdin);
            c.email[strcspn(c.email, "\n")] = 0;

            fseek(fp, -sizeof(Contact), SEEK_CUR);
            fwrite(&c, sizeof(Contact), 1, fp);

            printf("Contact updated successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Contact with ID %d not found.\n", id);

    fclose(fp);
}





void delete_contact() 
{
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) { printf("No contacts to delete.\n"); return; }

    FILE *temp = fopen("temp.dat", "wb");

    int id, found = 0;
    printf("Enter Contact ID to delete: ");
    scanf("%d", &id);
    getchar();

    Contact c;

    while (fread(&c, sizeof(Contact), 1, fp)) {
        if (c.id == id) {
            found = 1;
            continue;
        }
        fwrite(&c, sizeof(Contact), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("Contact deleted successfully!\n");
    else
        printf("Contact ID not found.\n");
}




void sort_contacts() 
{
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) { printf("No contacts to sort.\n"); return; }

    Contact list[500];
    int count = 0;

    while (fread(&list[count], sizeof(Contact), 1, fp))
        count++;

    fclose(fp);

    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (strcmp(list[i].name, list[j].name) > 0) 
            {
                Contact temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }

    fp = fopen(FILE_NAME, "wb");
    fwrite(list, sizeof(Contact), count, fp);
    fclose(fp);

    printf("Contacts sorted A-Z successfully!\n");
}
