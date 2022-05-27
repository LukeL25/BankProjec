#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

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
    char name[15];
    int age;
    int member_code;
    account_t **accounts;
} bank_user_t;

//Functions:

/** Creates a user account and generates a member code **/
int create_user_account(char *name, int age);
/** Edits user accounts. Their specific code is needed. **/
int edit_user_account(int mem_code);
/** Creates an account for the user **/
int create_account(int mem_code, enum ACCOUNT_TYPE type);


#endif