#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_ACCOUNTS 100

typedef struct BankAccount
{
	char accountHolder[100];
	int accountNumber;
	float balance;	
}

void createAccount(struct BankAccount accounts[], int *n)