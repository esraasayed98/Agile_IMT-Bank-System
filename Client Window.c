/*************************************************/
/*       Agile Software Development Project      */
/*       Description: Client Window                */
/*       Date:10 May 2022                         */
/*       Version: v01                            */
/*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Bank account.h"


void Login();

int main()
{
    //clients data
	AccountsInit();
    Login();
    return 0;

}

void Login()
{
    unsigned long long int ID;
	unsigned long long int password;
	printf("Enter Account ID: ");
	scanf("%lld", &ID);
	printf("\nEnter password: ");
	scanf("%lld", &password);

    //validate 
    BankAccount client;
    List_voidRetriveBYID(ID,&L,&client); //need to handle if the account doesn't exist

     
    if (client.Password == password)
    {
        system("cls");

        printf("\n ********************************************************************************************************************\n");
        printf("\n                                                  Account Details                                                    \n");
        printf("\n ********************************************************************************************************************\n");
        
        printf("\n          Welcome %s", client.name);
        printf("\nClient Address: %s", client.Address);
        printf("\nClient National ID: %lld", client.NationalID);
        printf("\nClient Age: %d", client.Age);
        printf("\nAccount Status: %s", client.Account_Status);
        printf("\nClient Balance: %lld", client.Balance);
        if (client.Guardian_NationalID!=0)
        {
            printf("\nClient Guardian National ID: %lld", client.Guardian_NationalID);
        }
    }
    else
    {
        printf("\nWrong Password");
        printf("\nEnter password: ");
	    scanf("%lld", &password);

    }


}



void open_existing_account(){
	system("cls");

	BankAccount client;
    long long int Bank_Account_ID;
    // retrive elements of two clients
    printf("please input Account_ID:  ");
    scanf("%lld",&Bank_Account_ID);

    List_voidRetriveBYID(Bank_Account_ID,&L,&client);

	system("cls");

	printf("==========================================================================================\n");
    printf("==============================Account  Details ===========================================\n");
    
    printf("\nClient Name: %s", client.name);
	printf("\nClient Address: %s", client.Address);
	printf("\nClient National ID: %lld", client.NationalID);
	printf("\nClient Age: %d", client.Age);
	printf("\nAccount Status: %s", client.Account_Status);
	printf("\nClient Balance: %lld", client.Balance);
	if (client.Guardian_NationalID!=0)
	{
		printf("\nClient Guardian National ID: %lld", client.Guardian_NationalID);
	}

	Menu(&client);
	char c[2];
		
	
	printf("\nNeed to Make another operation(y/n)?");
	
	scanf("%s", &c[0]);
	
	while(c[0]=='y')
	{
		

		system("cls");
	
		Menu(&client);
		printf("\nNeed to Make another operation(y/n)?");
	
		scanf("%s", &c[0]);
	}

}
