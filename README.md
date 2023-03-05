## bear_robotics_TAKE-HOME-PROJECTS
This project implemented only the controller part of the ATM system, with the simple version of console UI.

### Installation and run
``` bash
$ make
$ ./API.out
```

### Step
1. Enter Card Number
1. Enter PIN Number
1. Choose account
1. Select service - 1. See Balance 2. Deposit 3. Withdraw
1. Go back to step 1 / step 4 / or just terminate program(You can choose).

*For each step, simple version of error handling was implemented for incorrect input*

### Testcases
Several accounts have been registered in the database for testing.
| CARD NUMBER | PIN | ACCOUNT | DEPOSIT |
| :--: | :--: | :--: | --: |
| 10 | 1000 | 11111111 | 0 |
| 10 | 1000 | 22222222 | 0 |
| 10 | 1000 | 33333333 | 0 |
| -- | ---- | -------- | - |
| 11 | 2000 | 44444444 | 0 |
| 11 | 2000 | 55555555 | 0 |
| -- | ---- | -------- | - |
| 12 | 3000 | 66666666 | 0 |
| 12 | 3000 | 77777777 | 0 |
| 12 | 3000 | 88888888 | 0 |
| 12 | 3000 | 99999999 | 0 |
| -- | ---- | -------- | - |
| 13 | 4000 | 12345678 | 0 |
| -- | ---- | -------- | - |
| 14 | 5000 | 87654321 | 0 |
| 14 | 5000 | 12341234 | 0 |
