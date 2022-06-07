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

/* Simple function to read in a bank user struct
 * from a binary file
 */
bank_user_t read_user_account(FILE *fp, int offset) {
    assert(fp != NULL);
    bank_user_t user = {0};
    fseek(fp, offset * sizeof(bank_user_t), SEEK_SET);
    int curr_position = 0;
    curr_position = ftell(fp);
    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    if (curr_position> length) {
        return BAD_USER;
    }
    fseek(fp, offset * sizeof(bank_user_t), SEEK_SET);
    fread(&user, sizeof(bank_user_t), 1, fp);
    return user;
} /* read_user_account() */

/* Finds user accounts using their given member code
 * by traversing the log files and comparing codes.
 * more efficient traversal method pending.
 */
bank_user_t find_user_account(int mem_code) {
    FILE *fp = fopen("logs.txt", "r");
    if (fp == NULL) {
        return BAD_USER;
    }
    /* TODO might want to write a more efficient way to
     * traverse the accounts and grab the user. Will have to
     * write sort function first
     * 
     */ 
    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    for (int i = 0; (i * sizeof(bank_user_t)) < length; i++) {
        bank_user_t user = {0};
        user = read_user_account(fp, i);
        if (user.member_code == mem_code) {
            return user;
        }
    }
    return USER_NONEXIST;
} /* find_user_account() */

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

