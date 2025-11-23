#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LEN 100

void clear_input() {
    while(getchar() != '\n');
}

void generate_password();
void check_strength();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== PASSWORD GENERATOR & STRENGTH CHECKER =====\n");
        printf("1. Generate Password\n");
        printf("2. Check Password Strength\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Enter a number.\n");
            clear_input();
            continue;
        }

        switch (choice)
        {
            case 1:
                generate_password();
                break;
            case 2:
                check_strength();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

int get_yes_no(char *msg)
{
    int val;
    while (1)
    {
        printf("%s (1 = Yes, 0 = No): ", msg);
        if (scanf("%d", &val) == 1 && (val == 0 || val == 1))
            return val;

        printf("Invalid input. Enter 1 or 0 only.\n");
        clear_input();
    }
}

void generate_password()
{
    int length;
    char password[MAX_LEN];

    printf("\nEnter password length (4 - 100): ");

    if (scanf("%d", &length) != 1 || length < 4 || length > MAX_LEN)
    {
        printf("Invalid length! Must be between 4 and 100.\n");
        clear_input();
        return;
    }

    int use_upper = get_yes_no("Include Uppercase?");
    int use_lower = get_yes_no("Include Lowercase?");
    int use_numbers = get_yes_no("Include Numbers?");
    int use_symbols = get_yes_no("Include Symbols?");

    if(!use_upper && !use_lower && !use_numbers && !use_symbols)
    {
        printf("You must choose at least one character type!\n");
        return;
    }

    char pool[300] = "";

    if(use_upper) strcat(pool, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if(use_lower) strcat(pool, "abcdefghijklmnopqrstuvwxyz");
    if(use_numbers) strcat(pool, "0123456789");
    if(use_symbols) strcat(pool, "!@#$%^&*()_+[]{}<>?");

    srand(time(NULL));
    int pool_len = strlen(pool);

    for(int i = 0; i < length; i++)
    {
        password[i] = pool[rand() % pool_len];
    }
    password[length] = '\0';

    printf("\nGenerated Password: %s\n", password);
}

void check_strength()
{
    char password[MAX_LEN];
    int upper = 0, lower = 0, digit = 0, symbol = 0;

    printf("\nEnter password to check: ");
    scanf("%s", password);

    int len = strlen(password);

    for(int i = 0; i < len; i++)
    {
        if(isupper(password[i])) upper++;
        else if(islower(password[i])) lower++;
        else if(isdigit(password[i])) digit++;
        else symbol++;
    }

    printf("\nPassword Strength: ");

    if(len >= 8 && upper && lower && digit && symbol)
        printf("STRONG\n");
    else if(len >= 6 && (upper || digit) && lower)
        printf("MEDIUM\n");
    else
        printf("WEAK\n");
}
