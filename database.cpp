#include "database.h"

CUSTOMER user_list[50000];
int total_user = 0;

void add_user(int card, int pin) {
	user_list[total_user].card_num = card;
	user_list[total_user].PIN = pin;
	user_list[total_user++].account_num = 0;
}

int db_idx(int card) {
	for (int i = 0;i < total_user;i++) {
		if (user_list[i].card_num == card)
			return i;
	}
	return -1;
}

void add_account(int card, int account) {
	int idx = db_idx(card);
	ACCOUNT* new_account = &user_list[idx].ACCOUNT_list[user_list[idx].account_num++];
	new_account->account = account;
	new_account->balance = 0;
}

bool verify_card_num_db(int card) {
	if (db_idx(card) == -1)
		return false;
	else
		return true;
}

bool verify_pin_num_db(int card, int pin) {
	int idx = db_idx(card);
	if (user_list[idx].PIN == pin)
		return true;
	else
		return false;
}

ACCOUNT_LIST get_account_list_db(int card) {
	int idx = db_idx(card);
	ACCOUNT_LIST ret;
	ret.account_num = user_list[idx].account_num;
	for (int i = 0;i < ret.account_num;i++) {
		ret.account_list[i] = user_list[idx].ACCOUNT_list[i].account;
	}
	return ret;
}

int get_balance_db(int card, int account_idx) {
	int idx = db_idx(card);
	return user_list[idx].ACCOUNT_list[account_idx].balance;
}

bool deposit_db(int card, int account_idx, int amount) {
	int idx = db_idx(card);
	user_list[idx].ACCOUNT_list[account_idx].balance += amount;
	return true;
}

bool withdraw_db(int card, int account_idx, int amount) {
	int idx = db_idx(card);
	if (user_list[idx].ACCOUNT_list[account_idx].balance >= amount) {
		user_list[idx].ACCOUNT_list[account_idx].balance -= amount;
		return true;
	}
	return false;
}