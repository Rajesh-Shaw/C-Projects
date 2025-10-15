#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 500

struct Account {
    int accNo;
    char name[50];
    float balance;
    char type[20];
};

struct Account accounts[MAX];
int count = 0;

// Function declarations
void createAccount();
void displayAccounts();
void searchAccount();
void depositMoney();
void withdrawMoney();
void saveToFile();
void loadFromFile();
void recordTransaction(int accNo, const char *type, float amount, float balance);
void viewTransactions();


int main() 
{
    int choice;
    loadFromFile();

    while(1)
    {
        printf("\n=========== Bank Account Management System ===========\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. View Transactions\n");
        printf("7. Save & Exit\n");
        printf("======================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3: searchAccount(); break;
            case 4: depositMoney(); break;  
            case 5: withdrawMoney(); break;
            case 6: viewTransactions(); break;
            case 7: saveToFile();
                    printf("Data saved. Exiting...\n");
                    exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}





void createAccount()
{
    if(count>=MAX)
    {
        printf("Account database full!\n");
        return;
    }

    struct Account acc;
    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);
    getchar();

    printf("Enter Account Holder Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';

    printf("Enter Account Type (Savings/Current): ");
    fgets(acc.type, sizeof(acc.type), stdin);
    acc.type[strcspn(acc.type, "\n")] = '\0';

    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    accounts[count++] = acc;
    printf("Account Created Successfully for %s (A/C No: %d)\n", acc.name, acc.accNo);

}

void displayAccounts()
{
    if(count == 0)
    {
        printf("No Account record.");
        return;
    }

    for(int i=0; i<count; i++)
    {
        printf("Account Number: %d | Holder Name: %s | Type: %s  | Balance: %0.2f\n",
                        accounts[i].accNo, accounts[i].name, accounts[i].type, accounts[i].balance);
    }
}

void searchAccount()
{
    if(count == 0)
    {
        printf("No Account records.");
        return;
    }
    
    int accNo, found = 0;
    printf("Enter Account Number to Search: ");
    scanf("%d", &accNo);

    for(int i=0; i<count; i++)
    {
        if(accounts[i].accNo == accNo)
        {
            printf("Account Number: %d  | Account Holder Name: %s  | Account Type: %s  | Account Balance: %f",
                        accounts[i].accNo, accounts[i].name, accounts[i].type, accounts[i].balance);
            
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("No Account Found with this account number %d.", accNo);
    }

}

void depositMoney()
{
    if(count == 0)
    {
        printf("No Account record.");
        return;
    }
    
    int accNo, found = 0;
    float depositAmount=0;
    printf("Enter Account Number to deposit Money: ");
    scanf("%d", &accNo);

    for(int i=0; i<count; i++)
    {
        if(accounts[i].accNo == accNo)
        {
            printf("Current Balance: %.2f\n", accounts[i].balance);
            printf("Enter amount to Deposit: ");
            scanf("%f", &depositAmount);

            accounts[i].balance += depositAmount;
            recordTransaction(accNo, "Deposit", depositAmount, accounts[i].balance);           
            
            printf("Deposited Rs%.2f successfully! New Balance: Rs%.2f\n", depositAmount, accounts[i].balance);
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("No Account Found with this account number %d.", accNo);
    }


}

void withdrawMoney()
{
    if(count == 0)
    {
        printf("No account records found.\n");
        return;
    }

    int accNo, found = 0;
    float withdrawAmount;

    printf("Enter Account Number to withdraw money: ");
    scanf("%d", &accNo);

    for(int i=0; i<count; i++)
    {
        if(accounts[i].accNo == accNo)
        {
            printf("Current Balance: %.2f\n", accounts[i].balance);
            printf("Enter amount to withdraw: ");
            scanf("%f", &withdrawAmount);

            if(withdrawAmount > accounts[i].balance)
            {
                printf("Insufficient balance!\n");
                return;
            }

            accounts[i].balance -= withdrawAmount;
            recordTransaction(accNo, "Withdraw", withdrawAmount, accounts[i].balance);

            printf("Withdrawal of Rs%.2f successful! New Balance: Rs%.2f\n", withdrawAmount, accounts[i].balance);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No account found with number %d.\n", accNo);

}

void saveToFile()
{
    FILE *fp = fopen("accounts.txt", "w");
    if(fp == NULL)
    {
        printf("Error saving file!\n");
        return;
    }

    for(int i=0; i<count; i++)
    {
        fprintf(fp,"%d,%s,%s,%f\n",accounts[i].accNo, accounts[i].name, accounts[i].type, accounts[i].balance);
    }
    fclose(fp);
    printf("Account data saved successfully.\n");
}

void loadFromFile()
{
    FILE *fp = fopen("accounts.txt", "r");
    if(fp == NULL)
    {
        printf("No previous record found.\n");
        return;
    }

    while( fscanf(fp,"%d,%49[^,],%19[^,],%f",&accounts[count].accNo, accounts[count].name, accounts[count].type, &accounts[count].balance) == 4 )
    {
        count++;
    }
    fclose(fp);
    printf("Loaded %d Account records from file.\n", count);
}

void recordTransaction(int accNo, const char *type, float amount, float balance)
{
    FILE *fp = fopen("transactions.txt", "a");
    if(fp == NULL)
    {
        printf("Error recording transaction.\n");
        return;
    }

    time_t t;
    struct tm *tm_info;
    char date[30];

    time(&t);
    tm_info = localtime(&t);
    strftime(date, sizeof(date), "%d-%m-%Y %H:%M", tm_info);

    fprintf(fp,"%d,%s,%.2f,%.2f,%s\n", accNo, type, amount, balance, date);
    fclose(fp);
}

void viewTransactions()
{
    FILE *fp = fopen("transactions.txt", "r");
    if(fp == NULL)
    {
        printf("No transaction history found.\n");
        return;
    }

    int accNo;
    char type[20], date[30];
    float amount, balance;

    printf("\n--- Transaction History ---\n");
    while(fscanf(fp, "%d,%19[^,],%f,%f,%[^\n]\n", &accNo, type, &amount, &balance, date) == 5)
    {
        printf("Account No: %d | Type: %s | Amount: Rs%.2f | Balance After: Rs%.2f | %s\n",
               accNo, type, amount, balance, date);
    }

    fclose(fp);

}
