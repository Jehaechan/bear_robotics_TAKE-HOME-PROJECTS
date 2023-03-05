#pragma once
typedef struct ACCOUNT {
	int account;
	int balance;
}ACCOUNT;

typedef struct CUSTOMER {
	int card_num;
	int PIN;
	int account_num;
	ACCOUNT ACCOUNT_list[30];
}CUSTOMER;

typedef struct ACCOUNT_LIST {
	int account_num;
	int account_list[30];
}ACCOUNT_LIST;

void add_user(int card, int pin);
int db_idx(int card);
void add_account(int card, int account);
bool verify_card_num_db(int card);
bool verify_pin_num_db(int card, int pin);
ACCOUNT_LIST get_account_list_db(int card);
int get_balance_db(int card, int account_idx);
bool deposit_db(int card, int account_idx, int amount);
bool withdraw_db(int card, int account_idx, int amount);