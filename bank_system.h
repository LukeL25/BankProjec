#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#define ERROR (0)
#define SUCCESS(1)


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
    char *first_name;
    char *last_name;
    int age;
    int member_code;
    account_t **accounts;
} bank_user_t;

/* Function prototypes */:

int create_user_account(char *, char *, int);
int edit_user_account(int);
int find_user_account(int);
int create_account(int, enum ACCOUNT_TYPE);
int search_logs();
int withdraw_deposit();
void generate_code();
void sort_accounts();

#endif