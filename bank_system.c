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
    /* Creating bank user from parameters */
    bank_user_t user = {0};
    strncpy(user.first_name, first_name, FIRST_NAME_LENGTH);
    strncpy(user.last_name, last_name, LAST_NAME_LENGTH);
    user.age = age;
    /* Writing to bank logs */
    FILE *fp = fopen("logs.txt", "r");
    if (fp == NULL) {
        return ERROR;
    }
    fseek(fp, 0, SEEK_END);
    int status = fwrite(&user, 1, sizeof(bank_user_t), fp);
    if (status != 1) {
        return ERROR;
    }
    fclose(fp);
    fp = NULL;
    return SUCCESS;
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

