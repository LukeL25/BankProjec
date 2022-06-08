#include "bank_system.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        printf("Welcome to Lawson Banking! Select One:\n1. Log In\n2. Create New Account\n3. Exit");
        char user_choice = ' ';
        scanf(" %c ", &user_choice);
        if (user_choice == '1') {
            printf("input member code:\n");
            int mem_code = 0;
            scanf("%d", &mem_code);
            if (mem_code == ERROR) {
                printf("Falied to login, either account does not exist or credentials were inputted incorrectly.\n");
            }
            else {
                printf("successfully logged in!\n");

            }
        }
        else if (user_choice == '2') {
            
        }
        else if(user_choice == '3') {

        }
    
    }
}

