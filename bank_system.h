#include <stdlib.h>
#include <stdio.h>

#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#define ERROR (-1)
#define SUCCESS (1)
#define FIRST_NAME_LENGTH (15)
#define LAST_NAME_LENGTH (20)
#define FILENAME ("logs.txt")

#define USER_NONEXIST ((bank_user_t){\
    .first_name = "NONEXIST",\
    .last_name = "NOEXIST",\
    .age = -1,\
    .member_code = -1,\
})

#define BAD_USER ((bank_user_t){\
    .first_name = "BOGUS",\
    .last_name = "BOGUS",\
    .age = -1,\
    .member_code = -1,\
})

enum ACCOUNT_TYPE {
    checking,
    saving,
};

typedef struct account {
    enum ACCOUNT_TYPE type;
    float balance;
    char *record;
} account_t;

typedef struct bank_user {
    char first_name[FIRST_NAME_LENGTH];
    char last_name[LAST_NAME_LENGTH];
    int age;
    int member_code;
    account_t **accounts;
} bank_user_t;

/* Function prototypes */

int create_user_account(char *, char *, int);
int edit_user_account(int);
int find_user_account(int);
bank_user_t read_user_account(FILE *, int);
int write_user_account(FILE *, int);
int create_account(int, enum ACCOUNT_TYPE);
int search_logs();
int withdraw_deposit();
int generate_code();
void sort_accounts();

/* UI Functions: */
void user_account_navig();

#endif