#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int acc_no;
    char name[50];
    int pin;
    float balance;
};

void createAccount() 
{
    FILE *fp = fopen("accounts.dat", "ab");
    struct Account acc;

    printf("\n--- Create New Account ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);
    getchar();

    printf("Enter Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = 0;

    printf("Set 4-digit PIN: ");
    scanf("%d", &acc.pin);

    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account Created Successfully!\n");
}

int login(struct Account *loggedAcc) 
{
    FILE *fp = fopen("accounts.dat", "rb");
    struct Account acc;
    int acc_no, pin;

    printf("\n--- Login ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_no);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    while (fread(&acc, sizeof(acc), 1, fp)) 
    {
        if (acc.acc_no == acc_no && acc.pin == pin) 
        {
            *loggedAcc = acc;
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void updateAccount(struct Account updatedAcc) 
{
    FILE *fp = fopen("accounts.dat", "rb+");
    struct Account acc;

    while (fread(&acc, sizeof(acc), 1, fp)) 
    {
        if (acc.acc_no == updatedAcc.acc_no) {
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&updatedAcc, sizeof(acc), 1, fp);
            break;
        }
    }
    fclose(fp);
}

void atmMenu(struct Account acc) {
    int choice;
    float amount;
    int newPin;

    while (1) {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Change PIN\n");
        printf("5. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Balance: %.2f\n", acc.balance);
                break;

            case 2:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                acc.balance += amount;
                updateAccount(acc);
                printf("Deposit Successful!\n");
                break;

            case 3:
                printf("Enter withdraw amount: ");
                scanf("%f", &amount);
                if (amount > acc.balance) {
                    printf("Insufficient Balance!\n");
                } else {
                    acc.balance -= amount;
                    updateAccount(acc);
                    printf("Withdrawal Successful!\n");
                }
                break;

            case 4:
                printf("Enter new PIN: ");
                scanf("%d", &newPin);
                acc.pin = newPin;
                updateAccount(acc);
                printf("PIN Updated!\n");
                break;

            case 5:
                printf("Logging out...\n");
                return;

            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    int choice;
    struct Account acc;

    while (1) {
        printf("\n===== ATM SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                if (login(&acc)) {
                    printf("Login Successful! Welcome %s\n", acc.name);
                    atmMenu(acc);
                } else {
                    printf("Invalid Account or PIN!\n");
                }
                break;

            case 3:
                printf("Thank you for using ATM System!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
