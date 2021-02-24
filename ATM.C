#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
void amount(void);
void withdraw(void);
void deposit(void);
void quit(void);
int choice, pin, k;
char transaction ='y';
void main(void)
{
time_t t;
time(&t);
clrscr();
printf("\t\t WELCOME TO BANKING SYSTEM \n");
while (pin != 7891)
{
printf("ENTER YOUR  PIN NUMBER:\n");
scanf("%d", &pin);
if (pin != 7891)
printf("PLEASE ENTER VALID PASSWORD\n");
}
do
{
printf("********Welcome to ATM Service**************\n");
printf("1. Check Balance\n");
printf("2. Withdraw Cash\n");
printf("3. Deposit Cash\n");
printf("4. Quit\n");
printf("******************#**************************#*\n\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
amount();
break;
case 2:
withdraw();
break;
case 3:
deposit();
break;
case 4:
quit();
break;
default:
printf("\n INVALID CHOICE");
}
printf("\n\n\n DO U WISH TO HAVE ANOTHER TRANSCATION?(y/n): \n");
fflush(stdin);
scanf("%c", &transaction);
if (transaction == 'n'|| transaction == 'N')
k = 1;
} 
while (!k);
printf("\n\n THANKS FOR USING OUT ATM SERVICE");
}
void amount(void)
{
unsigned long amount=12098;
time_t t;
time(&t);
printf("\n YOUR BALANCE IN Rs : %lu ", amount);
printf("\n Today's date and time : %s",ctime(&t));
getche();
}
void withdraw(void)
{
unsigned long  amount=12098,withdraw;
time_t t;
time(&t);
printf("\n ENTER THE AMOUNT TO WITHDRAW: \n");
scanf("%lu", &withdraw);
if (withdraw % 100 != 0)
{
printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
}
else if (withdraw >(amount - 5000))
{
printf("\n INSUFFICENT BALANCE");
}
else
{
amount = amount - withdraw;
printf("\n\n PLEASE COLLECT CASH");
printf("\n YOUR CURRENT BALANCE IS :%lu", amount);
printf("\n Today's date and time : %s",ctime(&t));
getche();
}
}
void deposit(void)
{
unsigned long amount=12098,deposit;
time_t t;
time(&t);
printf("\n ENTER THE AMOUNT TO DEPOSIT\n");
scanf("%lu", &deposit);
amount = amount + deposit;
printf("YOUR BALANCE IS=%lu",amount);
printf("\n Today's date and time : %s",ctime(&t));
getche();
}
void quit(void)
{
time_t t;
time(&t);
printf("\n THANK U USING ATM");
printf("\n Today's date and time : %s",ctime(&t));
getche();
}
