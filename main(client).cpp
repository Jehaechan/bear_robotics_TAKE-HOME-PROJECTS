#include <stdio.h>
#include "server.h"
#include "database.h"
#include "main.h"

int main() {
	init();
	int account_idx = 0;
STEP1:
	int card_num = insert_card();
	if (verify_card_num(card_num) == false) {
		printf("Wrong Card Number!\n");
		{
			int mode = error_handling();
			if (mode)
				goto END;
			else
				goto STEP1;
		}
	}

STEP2:
	int token;
	if ((token = verify_pin_num(card_num, get_pin())) < 0) {
		printf("Wrong PIN Number!\n");
		{
			int mode = error_handling();
			if (mode)
				goto END;
			else
				goto STEP2;
		}
	}

STEP3:
	account_idx = chooose_account(token);

	{
		int balance = get_balance(token, account_idx);

	STEP4:
		int service = choose_service(token);
		if (service == 1) {
			printf("Current Balance: $%d\n\n",balance);
		}
		else if (service == 2) {
			if (deposit_cash(token, account_idx) == false) {
				printf("Error(Server side)!\n\n");
				goto END;
			}
			printf("Success!\nYour Deposit: $%d\n\n", balance = get_balance(token, account_idx));
		}
		else if (service == 3) {
			if (withdraw_cash(token, account_idx, balance) == false) {
				printf("Error(Server side)!\n\n");
				goto END;
			}
			printf("Success!\nYour Deposit: $%d\n\n", balance = get_balance(token, account_idx));
		}

		int mode = choose_mode();
		if (mode == 1) {
			goto END;
		}
		else if (mode == 2) {
			goto STEP4;
		}
		else {
			return_token(token);
			goto STEP1;
		}
	}

END:
	printf("END!\n");
	return_token(token);
	return 0;
}