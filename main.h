#pragma once
#include <stdio.h>
#include "server.h"
#include "database.h"

// for testing
void init() {
	add_user(10, 1000);
	add_user(11, 2000);
	add_user(12, 3000);
	add_user(13, 4000);
	add_user(14, 5000);

	add_account(10, 11111111);
	add_account(10, 22222222);
	add_account(10, 33333333);

	add_account(11, 44444444);
	add_account(11, 55555555);

	add_account(12, 66666666);
	add_account(12, 77777777);
	add_account(12, 88888888);
	add_account(12, 99999999);

	add_account(13, 12345678);

	add_account(14, 87654321);
	add_account(14, 12341234);
}

int insert_card() {
	int card;
	printf("PLEASE INSERT YOUR CARD\n");
	printf("card num(integer val): ");
	scanf("%d", &card);
	printf("\n");
	return card;
}

int error_handling() {
	printf("<1>: Try Again\t\t<2>: Exit\n");
	printf("press: ");
	int mode;
	scanf("%d", &mode);
	printf("\n");
	return mode - 1;
}

int get_pin() {
	int PIN;
	printf("Please enter your PIN: ");
	scanf("%d", &PIN);
	printf("\n");
	return PIN;
}

int chooose_account(int token) {
	ACCOUNT_LIST list = get_account_list(token);
	while (1) {
		printf("<ACCOUNT_LIST>\n");
		for (int i = 0;i < list.account_num;i++) {
			printf("%d. %d\n", i + 1, list.account_list[i]);
		}
		int ret;
		printf("Which Account? ");
		scanf("%d", &ret);
		if (ret > 0 && ret <= list.account_num) {
			printf("\n");
			return ret - 1;
		}
		printf("Invalid Account! Try Again.\n\n");
	}
}

int choose_service(int token) {
	while (1) {
		printf("<Select your service>\n");
		printf("1. See Balance\n");
		printf("2. Deposit\n");
		printf("3. Withdraw\n");
		printf("Enter service: ");
		int mode;
		scanf("%d", &mode);
		if (mode < 1 || mode>3) {
			printf("Invalid Input! Try again!\n\n");
			continue;
		}
		printf("\n");
		return mode;
	}
}

bool deposit_cash(int token, int account_idx) {
	int cash;
	printf("Insert Cash: ");
	scanf("%d", &cash);
	return deposit(token, account_idx, cash);
}

bool withdraw_cash(int token, int account_idx, int cur_balance) {
	while (1) {
		int cash;
		printf("Enter an amount: ");
		scanf("%d", &cash);
		if (cur_balance < cash) {
			printf("Please enter a smaller amount than the current balance($%d).\n\n", cur_balance);
			continue;
		}
		return withdraw(token, account_idx, cash);
	}
}

int choose_mode() {
	while (1) {
		printf("Is there anything else that you need?\n");
		printf("1. Exit\n");
		printf("2. Go to previous step\n");
		printf("3. Go to first step\n");
		printf("Enter: ");
		int mode;
		scanf("%d", &mode);
		if (mode < 1 || mode > 3) {
			printf("Invalid Input! Try again.\n\n");
			continue;
		}
		else {
			printf("\n");
			return mode;
		}
	}
}
