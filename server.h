#pragma once
#include "database.h"

bool verify_card_num(int card_num);
int verify_pin_num(int card_num, int PIN);
ACCOUNT_LIST get_account_list(int token_num);
int get_balance(int token_num, int account_idx);
void return_token(int token_num);
bool deposit(int token_num, int account_idx, int cash);
bool withdraw(int token_num, int account_idx, int cash);