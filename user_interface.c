#include "bank_system.h"
#include "bank_system.c"
#include <stdio.h>
#include <stdlib.h>

void user_account_navig() {
    printf("hehe\n");
}

int main() {
    while (1) {
        printf("Welcome to Lawson Banking! Select One:\n1. Log In\n2. Create New Account\n3. Exit\n");
        char user_choice = ' ';
        scanf(" %c ", &user_choice);
        if (user_choice == '1') {
            while (1) {
                printf("input member code (type 3 anytime to exit to main menu):\n");
                int mem_code = 0;
                scanf("%d", &mem_code);
                if (mem_code == 3) {
                    break;
                }
                int account_location = find_user_account(mem_code);
                if (account_location == ERROR) {
                    printf("Falied to login, either account does not exist or credentials were inputted incorrectly.\n");
                    
                }
                else if (account_location == SUCCESS) {
                    printf("successfully logged in!\n");
                    user_account_navig();
                } 
            }
        }
        if (user_choice == '2') {
            char first_name[FIRST_NAME_LENGTH];
            char last_name[LAST_NAME_LENGTH];
            int age;
            printf("To create a user account, first enter in your first name:\n");
            scanf("%14s\n", &first_name);
            printf("Now eneter your last name:\n");
            scanf("%20s\n", &last_name);
            printf("Lastly, enter your name:\n");
            scanf("%d\n", &age);
            int mem_code = create_user_account(first_name, last_name, age);
            if (mem_code == ERROR) {
                printf("Error occurred, cannot create account at this time. Returning to menu....\n");
                continue;
            }
            printf("Here is your new member code: %d, DO NOT LOSE THIS. It's required for login.", &mem_code);
            continue;
        }
        else if (user_choice == '3') {
            break;
        }
    }
}
