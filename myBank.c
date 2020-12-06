#include <stdio.h>
#include <math.h>
#define NORMILIZE 901
#define TRUE 1
#define FALSE 0
int accountSize=0;
float bankAccount[50][2] = {0};

int valid_scanf(int scanfInput)
{
    if (scanfInput == 0)
    {
        return FALSE;
    }
    return TRUE;
}

int is_Interest_Valid(double interestRate)
{
    if(interestRate < 0)
    {
        printf("Invalid interest rate\n");
        return FALSE;
    }
    return TRUE;
}
float two_Decimal_Points(float amount)
{
    int twoDecimalPoints = (int)(amount *100);
    amount = (float)twoDecimalPoints;
    return (amount/100);
}

int is_Amount_Valid(float amount)
{
    if (amount<0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int is_Account_Number_Valid_And_Still_Open(int accNum)
{
    if (accNum > 950 || accNum < 901 )
    {
        printf("Invalid account number /n");
        return FALSE;
    }
    int updatedAccNum = accNum-NORMILIZE;
    if(bankAccount[updatedAccNum][1] == FALSE)
    {
        printf("This account is already closed\n");
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int is_Account_Number_Valid_And_Open(int accNum)
{
    if (accNum > 950 || accNum < 901 )
    {
        printf("Invalid account number\n");
        return FALSE;
    }
    int updatedAccNum = accNum-NORMILIZE;
    if(bankAccount[updatedAccNum][1] == FALSE)
    {
        printf("This account is closed\n");
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void openAccount(float amount)
{
    float newAmount;
    if(!is_Amount_Valid(amount))
    {      
        printf("Invalid Amount");
    }
    else
    {
    newAmount = two_Decimal_Points(amount);

      if (accountSize==50)
      {
        printf("Sorry, all bank accounts are currently open");
      }

        if(bankAccount[accountSize][1] == 0&&accountSize<50)
         {
            bankAccount[accountSize][1] = TRUE;
            bankAccount[accountSize][0] = newAmount;
            printf("New account number is: %d",(NORMILIZE+accountSize));
            accountSize++;
         }
    }
}
 

void balanceInquiry(int accountNumber)
{
    if (is_Account_Number_Valid_And_Open(accountNumber))
    {
        float balance = bankAccount[accountNumber-NORMILIZE][0];
        printf("The balance of account number %d is: %0.2f\n",accountNumber,two_Decimal_Points(balance));
    }
}


void deposit_In_Account(int accNum, float amount)
{
int is_Scanf_Valid;
    if(is_Account_Number_Valid_And_Open(accNum))
    {
        printf("Please enter the amount to deposit: ");
        is_Scanf_Valid = scanf(" %f", &amount);
        if (!valid_scanf(is_Scanf_Valid))
        {
            printf("Failed to read the amount\n");
        }
        else {
        if (!is_Amount_Valid(amount))
        {  
            printf("Cannot deposit a negitive amount\n");
        }

        else
        {
            int updatedAccNum = accNum-NORMILIZE;
            float updatedBalance = (bankAccount[updatedAccNum][0] + amount);
            printf("The new balance is: %0.2f\n",two_Decimal_Points(updatedBalance));
        }
    }
   }
}

void withdraw_From_Account(int accNum, float amount)
{
    int is_Scanf_Valid;
    int updatedAccNum = accNum - NORMILIZE;
    float current_Bank_Balance = bankAccount[updatedAccNum][0];
    float updatedBalance = 0;
    if (is_Account_Number_Valid_And_Open(accNum))
    {
      printf("Please enter the amount to withdraw: ");
      is_Scanf_Valid = scanf(" %f", &amount);
      if (!valid_scanf(is_Scanf_Valid))
      {
         printf("Failed to read the amount\n"); 
      }
      else {
        if(!is_Amount_Valid(amount))
        {
            printf("Cannot withdraw a negitive amount\n");
        }
        else {
        
        if (current_Bank_Balance < amount)
        {
            printf("Cannot withdraw more than the balance\n");
        }
        else
        {
        updatedBalance = current_Bank_Balance - amount;
        bankAccount[updatedAccNum][0]=updatedBalance;
        printf("The new balance is: %0.2f\n",two_Decimal_Points(updatedBalance));
    }
    
            }
    
  }
 }
    
}

void closeAccount(int accNum)
{
    int updated_Acc_Num = accNum - NORMILIZE;
    if (is_Account_Number_Valid_And_Still_Open(accNum))
    {
        bankAccount[updated_Acc_Num][1] = FALSE;
        accountSize--;
        printf("Closed account number %d\n",accNum);
    }
}

void addInterest(int interestRate)
{
    double decemalInterest = (1+(interestRate/100.0));
    if (is_Interest_Valid(interestRate))
    {
        for (int i = 0; i < 50; i++)
        {
            if (bankAccount[i][1])
            {
                bankAccount[i][0] *= decemalInterest;
            }
        }
    }
}

void printAccounts()
{
    for (int i = 0; i < 50; i++)
    {
        if (bankAccount[i][1])
        {
            printf("The balance of account number %d is: %0.2f\n",(i+NORMILIZE),two_Decimal_Points(bankAccount[i][0]));
        } 
    }
}   

void end()
{
    for (int i = 0; i < 50; i++)
    {
        if (bankAccount[i][1])
        {
            bankAccount[i][1] = FALSE;
        }
    }
}
