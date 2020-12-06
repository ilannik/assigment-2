#include <stdio.h>
#include "myBank.h"
#define TRUE 1
#define FALSE 0

int was_Scanf_Intput_Valid(int scanfInput)
{
    if (scanfInput == 0)
    {
        return FALSE;
    }
    return TRUE;
}

void transactionsOptions()
{
    printf("\nPlease choose a transaction type:\n");
    printf(" O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
}

int main()
{
    int accountNumber;
    float amount;
    int is_Scanf_Valid;
    int interestRate;
    char transactionType;
    while (transactionType != 'E')
    {
        transactionsOptions();
        scanf(" %c", &transactionType);
        switch (transactionType)
        {
        case 'O':
            printf("Please enter amount for deposit: ");
            is_Scanf_Valid = scanf(" %f", &amount);
            if (!was_Scanf_Intput_Valid(is_Scanf_Valid))
            {
                printf("Failed to read the amount\n");
            }
            else
            {
                openAccount(amount);
                printf("\n");
            }
            break;

        case 'B':
            printf("Please enter account number: ");
            is_Scanf_Valid = scanf(" %d", &accountNumber);
            if (!was_Scanf_Intput_Valid(is_Scanf_Valid))
            {
                printf("Failed to read the account number\n");
            }
            else
            {
                balanceInquiry(accountNumber);
            }
            break;

        case 'D':
            printf("Please enter account number: ");
            is_Scanf_Valid = scanf(" %d", &accountNumber);
            if (!was_Scanf_Intput_Valid(is_Scanf_Valid))
            {
                printf("Failed to read the account number\n");
            }
            else
              {
                deposit_In_Account(accountNumber, amount);
              }
            break;

        case 'W':
            printf("Please enter account number: ");
            is_Scanf_Valid = scanf("%d", &accountNumber);
            if (!was_Scanf_Intput_Valid(is_Scanf_Valid))
            {
                printf("Failed to read the account number\n");
            }
            else
            {
                 withdraw_From_Account(accountNumber, amount);
            }
            
            break;

        case 'C':
            printf("Please enter account number: ");
            is_Scanf_Valid = scanf(" %d", &accountNumber);
            if (!was_Scanf_Intput_Valid(is_Scanf_Valid))
            {
                printf("Failed to read the account number\n");
            }
            else
            {
                closeAccount(accountNumber);
            }
            break;

        case 'I':
            printf("Please enter interest rate: ");
            is_Scanf_Valid = scanf(" %d", &interestRate);
            if (!was_Scanf_Intput_Valid(is_Scanf_Valid))
            {
                printf("Failed to read the interest rate\n");
            }
            else
            {
              
                addInterest(interestRate);
            }
            break;

        case 'P':
            printAccounts();
            break;

        case 'E':
            end();
            break;

        default:
            printf("Invalid transaction type\n");
            break;
        }
    }
    return 0;
}
