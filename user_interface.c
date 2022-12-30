#include "bank_system.h"
#include "bank_system.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        printf("Welcome to Lawson Banking! Select One:\n1. Log In\n2. Create New Account\n3. Exit\n");
        int user_choice;
        scanf("%d", &user_choice);
        if (user_choice == 1) {
            while (1) {
                printf("input member code (type 3 anytime to exit to main menu):\n");
                int mem_code = 0;
                scanf("%d", &mem_code);
                printf("%d\n", &mem_code);
                if (mem_code == 3) {
                    break;
                }
                int account_location = find_user_account(mem_code);
                if (account_location == ERROR) {
                    printf("Falied to login, either account does not exist or credentials were inputted incorrectly.\n");
                    continue;
                }
                else if (account_location != ERROR) {
                    printf("successfully logged in!\n");
                    /* Opening a file pointer to grab user data, I don't know
                     * if I should be doing all this behind the scenes in bank_system.c,
                     * but this is just a temporary fix.
                     */
                    FILE *file_pointer = fopen(FILENAME, "r");
                    bank_user_t user = read_user_account(file_pointer, account_location);
                    printf("%s\n", user.first_name);
                    fclose(file_pointer);
                    file_pointer = NULL;
                    user_account_navig();
                } 
            }
        }
        if (user_choice == 2) {
            char first_name[FIRST_NAME_LENGTH];
            char last_name[LAST_NAME_LENGTH];
            int age;
            printf("To create a user account, first enter in your first name:\n");
            scanf("%14s", &first_name);
            printf("Now enter your last name:\n");
            scanf("%20s", &last_name);
            printf("Lastly, enter your age:\n");
            scanf("%d", &age);
            int mem_code = create_user_account(first_name, last_name, age);
            if (mem_code == ERROR) {
                printf("Error occurred, cannot create account at this time. Returning to menu....\n");
                continue;
            }
            printf("Here is your new member code: %d, DO NOT LOSE THIS. It's required for login.", &mem_code);
            continue;
        }
        else if (user_choice == 3) {
            printf("Thank you for your service!\n");
            break;
        }
    }
}
