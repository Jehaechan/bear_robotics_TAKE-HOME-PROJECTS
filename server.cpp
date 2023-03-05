#include "database.h"
#define MOD 511

typedef struct user_node {
	int card;
	int pin;
}user_node;

user_node user_list[512];
bool token[512];

int get_token(int card_num, int pin_num) {
	int i = 0;
	while (1) {
		if (token[i] == false) {
			user_list[i].card = card_num;
			user_list[i].pin = pin_num;
			token[i] = true;
			return i;
		}
		i = (i + 1) | MOD;
	}
}

bool verify_card_num(int card_num) {
	return verify_card_num_db(card_num);
}

int verify_pin_num(int card_num, int PIN) {
	if (verify_pin_num_db(card_num, PIN) == false)
		return -1;
	return get_token(card_num, PIN);
}

ACCOUNT_LIST get_account_list(int token_num) {
	return get_account_list_db(user_list[token_num].card);
}

int get_balance(int token_num, int account_idx) {
	return get_balance_db(user_list[token_num].card, account_idx);
}

void return_token(int token_num) {
	token[token_num] = false;
}

bool deposit(int token_num, int account_idx, int cash) {
	return deposit_db(user_list[token_num].card, account_idx, cash);
}

bool withdraw(int token_num, int account_idx, int cash) {
	return withdraw_db(user_list[token_num].card, account_idx, cash);
}