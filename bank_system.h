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

#endif