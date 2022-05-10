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
#include "ListLinkedBased.h"




/**************************************************/
/***************Functions Prototypes***************/
/**************************************************/


BankAccount CreateBankAccount();
void AccountsInit();
void Insert_Name( BankAccount* client_Account);
void InsertAddress(BankAccount* client_Account);
void  InsertNationalID(long long int* NationalID);
void InsertAge(BankAccount* client_Account);
void CreateBankAccountID(BankAccount* client_Account);
void AccountStatus(BankAccount* client_Account,int closed);
void AccountBalance(BankAccount* client_Account);
void CreatePassword(BankAccount* client_Account);

List L;//List of accounts

// int main()
// {
//     printf("==============================================================================================\n");
//     printf("==============================Add New Bank Account ===========================================\n");
//     // CreateBankAccount();

//     AccountsInit();
//     return 0;

// }

BankAccount CreateBankAccount()
{
    BankAccount NewAccount;

    /*** 1. Full name****/
    Insert_Name(&NewAccount );

    // printf("Your Name: ");
    // puts(NewAccount.name ); 
    
    /*** 2. Full Address****/
    InsertAddress(&NewAccount);

    // printf("Your Address: ");
    // puts(NewAccount.Address);

    /*** 3. Insert National ID ***/
    InsertNationalID(&NewAccount.NationalID);
    // printf("%lld", NewAccount.NationalID);

    /*** 4. Insert Age ***/
    InsertAge(&NewAccount);
    // printf("Age:%d",NewAccount.Age);
    // printf("\nGuardin ID: %lld", NewAccount.Guardian_NationalID);

   

    /*** 5. Insert Bank Account ID ***/
    CreateBankAccountID(&NewAccount);
    printf("\nBank account ID: %lld ", NewAccount.BankAccountID);


    /*** 6. Insert Account Status ***/
    AccountStatus(&NewAccount,0);
    // printf("\nAccount Status is %s", NewAccount.Account_Status);


    /*** 7. Insert Account Balance ***/
    AccountBalance(&NewAccount);
    // printf("\nBalance in the Account: %lld", NewAccount.Balance);

    /*** 8. Create Random Password ***/
    CreatePassword(&NewAccount);
    printf("\nPassword: %lld ", NewAccount.Password);

    return NewAccount;



}

void Insert_Name( BankAccount* client_Account){

    
    int count=0;  
      
    // printf("Enter at least your first four names: ");

    fgets(client_Account->name , sizeof(client_Account->name), stdin);

        // print name
        // printf("Your Name: ");
        // puts(client_Account->name );   


        for(int i = 0; i < strlen(client_Account->name); i++) {  
            if(client_Account->name[i] == ' ')  
            {
            count++; 
            }
              
        } 

    /*** check number of letters ***/
    while(count< 3)
    {
        
        printf("Enter at least your first four names: ");
        count = 0;
        
        // read name
        fgets(client_Account->name , sizeof(client_Account->name), stdin);

        // print name
        // printf("Your Name: ");
        // puts(client_Account->name );   


        for(int i = 0; i < strlen(client_Account->name); i++) {  
            if(client_Account->name[i] == ' ')  
            {
            count++; 
            }
              
        }  

        

         
        

    // printf("Total number of spaces in the name: %d", count);
        
    }

    // Add name to the list


}

void InsertAddress(BankAccount* client_Account)
{
    
    printf("Enter Your Full Address: ");
    fgets(client_Account->Address, sizeof(client_Account->Address), stdin); 

    // print name
    // printf("Your Address: ");
    // puts(client_Account->Address);


    //Add address to List 


}

void InsertNationalID(long long int* NationalID)
{
    
    int count=0;

    while (count != 14)
    {
        count=0;

        printf("\nEnter A valid National ID: ");
        // printf("\nPlease Enter a valid National ID.");
        scanf("%lld", NationalID);

        // printf("%lld", client_Account->NationalID);
        
        // check the length of the national ID
    
        /**
        - iterate at least once, then until n becomes 0
        - remove last digit from n in each iteration
        - increase count by 1 in each iteration
        **/
       long long int n = *NationalID
;
        do {
            n /= 10;
            ++count;
        } while (n != 0);
        // printf("%d",count);
    }

  

 
}


void InsertAge(BankAccount* client_Account)
{
  
    printf("Enter Age: ");
    scanf("%d", &client_Account->Age);
    // printf("\n%d",client_Account->Age);


    if (client_Account->Age <21)
    {
        
        printf("\nneed Guardian");
        // Guardian NAtional ID
        InsertNationalID(&client_Account->Guardian_NationalID);
        // printf("\nGuardin ID: %lld", client_Account->Guardian_NationalID);

    }
    else
    {
        client_Account->Guardian_NationalID=0;

    }


}

void CreateBankAccountID(BankAccount* client_Account)
{
    

     // First digit must be non-zero:
     do
     {
         srand(time(0));//sets the starting point for producing random integers."acts as a seed"
         client_Account->BankAccountID = rand() % 10;
     } while(client_Account->BankAccountID == 0);
     
     for(int i = 1; i < 10; i++)
     {
         client_Account->BankAccountID *= 10; 
         client_Account->BankAccountID += rand() % 10;
     }
    //   printf("\nBank account ID: %lld ", client_Account->BankAccountID);


}


void AccountStatus(BankAccount* client_Account,int closed)
{
   

    // Restriction 
    if (closed ==1){
 
        strcpy(client_Account->Account_Status, "Restricted");

    }
    else
    {
        
        strcpy(client_Account->Account_Status, "Active");

    }
    // printf("\nAccount Status is %s", client_Account->Account_Status);

}

void AccountBalance(BankAccount* client_Account)
{
    
    printf("\nAdd Account Balance: ");
    scanf("%lld", &client_Account->Balance);
    // printf("\nBalance in the Account: %lld", client_Account->Balance);
}
void CreatePassword(BankAccount* client_Account)
{
    

    /***Create 10 digit Random Password***/
     
     // First digit must be non-zero:
     do
     {
        //  srand(17);//sets the starting point for producing random integers. "acts as a seed"
         client_Account->Password = rand() % 10;
     } while(client_Account->Password == 0);
     
     for(int i = 1; i < 10; i++)
     {
         client_Account->Password *= 10; 
         client_Account->Password += rand() % 10;
     }
    //   printf("\nPassword: %lld ", client_Account->Password);


}

void AccountsInit()
{
    // static int position=0;
    BankAccount client1, client2, client3;

    //client1
    strcpy(client1.name ,"Mahmoud Hassan Mohamed Mahmoud");
    strcpy(client1.Address ,"A 15 st");
    client1.NationalID=12345678912340;
    client1.Age = 24;
    client1.Guardian_NationalID = 0;
    client1.BankAccountID=1234567891;
    
    strcpy(client1.Account_Status ,"Active");
    client1.Balance=2500000;
    client1.Password=1023456789;

    //client2
    strcpy(client2.name ,"Ramez Essam");
    strcpy(client2.Address ,"B 30 st");
    client2.NationalID=12345678912340;
    client2.Age = 24;
    client2.Guardian_NationalID = 0;
    client2.BankAccountID=1234500891;
    strcpy(client2.Account_Status ,"Active");
    client2.Balance=2500000;
    client2.Password=1023450089;

    //client3
    strcpy(client3.name ,"Esraa Sayed");
    strcpy(client3.Address ,"c 30 st");
    client3.NationalID=12345678912340;
    client3.Age = 18;
    client3.Guardian_NationalID = 12005678912340;
    client3.BankAccountID=1000000000; 
    strcpy(client3.Account_Status ,"Active");
    client3.Balance=2500000;
    client3.Password=1023450089;

    
   

    List_voidInit(&L);
    // insert three clients to the list
    List_voidInsertList(L.Size,&L,client1);
    List_voidInsertList(L.Size,&L,client2);
    List_voidInsertList(L.Size,&L,client3);

    // printf("%d", L.Size);

    



    
   
}