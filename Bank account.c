/*************************************************/
/*       Agile Software Development Project      */
/*       Description:Bank Account                */
/*       Date:8 May 2022                         */
/*       Version: v01                            */
/*************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <time.h>
 



/**************************************************/
/***************Functions Prototypes***************/
/**************************************************/


void CreateBankAccount();
void Insert_Name();
void InsertAddress();
long long int  InsertNationalID();
void InsertAge();
void CreateBankAccountID();
void Guardian();
void AccountStatus(int closed);
void AccountBalance();
void CreatePassword();

int main()
{
    printf("==============================================================================================\n");
    printf("==============================Add New Bank Account ===========================================\n");
    CreateBankAccount();

    return 0;

}

void CreateBankAccount()
{
    /*** 1. Full name****/
    Insert_Name();

    /*** 2. Full Address****/
    InsertAddress();

    /*** 3. Insert National ID ***/
    InsertNationalID();

    /*** 4. Insert Age ***/
    InsertAge();

    /*** 5. Insert Bank Account ID ***/
    CreateBankAccountID();

    /*** 6. Insert Account Status ***/
    AccountStatus(0);

    /*** 7. Insert Account Balance ***/
    AccountBalance();

    /*** 8. Create Random Password ***/
    CreatePassword();




    

    
    


}

void Insert_Name(){


    char name[100];
    int count = 0;  


    /*** check number of letters ***/
    while(count< 3)
    {
        count = 0;
        printf("Enter at least your first four names: ");  
        
        // read name
        fgets(name, sizeof(name), stdin);

        // print name
        // printf("Your Name: ");
        // puts(name);   


        for(int i = 0; i < strlen(name); i++) {  
            if(name[i] == ' ')  
            {
            count++; 
            }
              
        }  
    // printf("Total number of spaces in the name: %d", count);
        
    }

    // Add name to the list


}

void InsertAddress()
{
    char Address[100];
    printf("Enter Your Full Address: ");
    fgets(Address, sizeof(Address), stdin); 

    // print name
    // printf("Your Address: ");
    // puts(Address);


    //Add address to List 


}

long long int InsertNationalID()
{

    long long int NationalID;
    int count=0;

    while (count < 14)
    {
        count=0;

        printf("\nEnter A valid National ID: ");
        // printf("\nPlease Enter a valid National ID.");
        scanf("%lld", &NationalID);
        // printf("%lld", NationalID);
        
        // check the length of the national ID
    
        /**
        - iterate at least once, then until n becomes 0
        - remove last digit from n in each iteration
        - increase count by 1 in each iteration
        **/
       long long int n = NationalID;
        do {
            n /= 10;
            ++count;
        } while (n != 0);
    }

    // printf("%lld", NationalID);
        
    return NationalID;
 
}


void InsertAge()
{
    int age;
    printf("Enter Age: ");
    scanf("%d", &age);
    // printf("\n%d",age);

    if (age <21)
    {
        printf("\nneed Guardian");
        Guardian();
    }


}

void CreateBankAccountID()
{
    unsigned long long int BankAccountID;

     // First digit must be non-zero:
     do
     {
         srand(time(0));//sets the starting point for producing random integers."acts as a seed"
         BankAccountID = rand() % 10;
     } while(BankAccountID == 0);
     
     for(int i = 1; i < 10; i++)
     {
         BankAccountID *= 10; 
         BankAccountID += rand() % 10;
     }
      printf("\nBank account ID: %lld ", BankAccountID);


}

void Guardian()
{
    // Guardian NAtional ID

    long long int Guardian_ID = InsertNationalID();
    printf("\nGuardin ID: %lld", Guardian_ID);

}

void AccountStatus(int closed)
{
   char Account_Status[10];

    // Restriction 
    if (closed ==1){
 
        strcpy(Account_Status, "Restricted");

    }
    else
    {
        
        strcpy(Account_Status, "Active");

    }
    printf("\nAccount Status is %s", Account_Status);

}

void AccountBalance()
{
    long long int Balance;
    printf("\nAdd Account Balance: ");
    scanf("%lld", &Balance);
    // printf("\nBalance in the Account: %lld", Balance);
}
void CreatePassword()
{

    /***Create 10 digit Random Password***/
     unsigned long long int Password;

     // First digit must be non-zero:
     do
     {
         srand(1);//sets the starting point for producing random integers. "acts as a seed"
         Password = rand() % 10;
     } while(Password == 0);
     
     for(int i = 1; i < 10; i++)
     {
         Password *= 10; 
         Password += rand() % 10;
     }
      printf("\nPassword: %lld ", Password);


}

