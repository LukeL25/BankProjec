#include "bank_system.h"
#include <stdio.h>
#include <stdlib.h>


/* The function create_user_account creates a user account
 * given a name and age
 */
int create_user_account(char *first_name, char *last_name, int age) {
    assert(first_name != NULL);
    assert(last_name != NULL);
    assert(age >= 18);
    bank_user_t user = {0};
    user.first_name = first_name;
    user.last_name = last_name;
    user.age = age;
    return 0;
} /* create_user_account */

int edit_user_account(int mem_code) {
    return 0;
}

int find_user_account(int mem_code) {
    return 0;
}

int create_account(int mem_code, enum ACCOUNT_TYPE type) {
    return 0;
}

int search_logs() {
    return 0;
}

int withdraw_deposit() {
    return 0;
}

void generate_code() {

}

void sort_accounts() {

}

