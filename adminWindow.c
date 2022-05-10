#include <stdio.h>
#include <stdlib.h>
#include "Bank account.h"
#include <conio.h>



/*************************************************/
/*       Agile Software Development Project      */
/*       Description: Admin Window                */
/*       Date:9 May 2022                         */
/*       Version: v01                            */
/*************************************************/


int display_login();
int validate_username_password(char username[], char password[]);
int create_new_account();
void open_existing_account();
void display_admin_window();

void Menu(BankAccount* account);
void Operation(int operation,BankAccount* account);
void changeAccountStatus(BankAccount* account);
void MakeTransaction();
void GetCash();
void Deposit();


int main(int argc, char *argv[]) {


	//clients data
	AccountsInit();

	//admin data
	AdminInit();


	int fail = display_login();
	
	while(fail){
		fail = display_login();
	}
	
	display_admin_window();
	return 0;
}




int validate_username_password(char username[], char password[]){
	return 1;
}

int create_new_account(){
	system("cls");
	// char details[20];
	// printf("Enter account details: ");
	// scanf("%s", &details);
	// printf("Hoooorraaaay! account created!");

	printf("==============================================================================================\n");
    printf("==============================Add New Bank Account ===========================================\n");
    BankAccount client;
	client= CreateBankAccount();
	List_voidInsertList(L.Size,&L,client);
	
	return 1;
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

	printf("==============================================================================================\n");
    printf("==============================Account  Details ===========================================\n");
    
    printf("\nClient Name: %s", client.name);
	printf("\nClient Address: %s", client.Address);
	printf("\nClient National ID: %lld", client.NationalID);
	printf("\nClient Age: %d", client.Age);
	printf("\nAccount Status: %s", client.Account_Status);
	printf("\nClient Balance: %lld", client.Balance);
	if (client.Guardian_NationalID!=0)
	{
		printf("\nClient Guardian National ID: %s", client.Guardian_NationalID);
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


void display_admin_window(){
	system("cls");
	int choice;
	printf("1. Create new account.\n");
	printf("2. Open existing account.\n");
	printf("3. Exit.\n");
	printf("\n Enter your choice: ");
	scanf("%d", &choice);
	
	if(choice == 3 ){
		return;
	}
	else if(choice == 1){
		create_new_account();
		char c[2];
		
		printf("\nNeed to Make another operation(y/n)?");
		
		scanf("%s", c);
		
		
		if(c[0]=='y')
		{
			system("cls");
		
			 display_admin_window();
		}
		
		
	}
	else if(choice == 2){
		
		open_existing_account();
	}
	else{
		display_admin_window();
	}
	
}



int display_login(){
	char username[20];
	char password[16];
	printf("Enter username: ");
	scanf("%s", username);
	printf("\n");
	printf("Enter password: ");
	scanf("%s", password);
	if (validate_username_password(username, password)){
		return 0;
	}
	else{
		printf("Wrong username or password, try again.");
		return 1;
	}
	
	
}



void Menu(BankAccount* account)
{
    printf("\n\n================== Operations ===================");
    printf("\n1. Make Transaction");
    printf("\n2. Change Account Status");
    printf("\n3. Get cash");
    printf("\n4. Deposit in Account");
    printf("\n5. Return to Main Menu");

     printf("\n\nPlease select an operation: ");

    int operation;
    scanf("%d",&operation);
    Operation(operation, account);





}

void Operation(int operation,BankAccount* account)
{
   

    switch(operation)
    {
        case 1:
            MakeTransaction();
            // Menu();
            break;
        case 2:
            changeAccountStatus(account);
            // Menu();
            break;
        case 3 :
            GetCash();
            // Menu();
            break;
        case 4:
            Deposit();
            // Menu();
            break;
        case 5:
            display_admin_window();
            break;
        default:
            printf("\nPlease select from the menu\n");
            // Menu();
			break;
        
    }
}





void MakeTransaction()
{
    printf("Make Transaction\n");
}

void changeAccountStatus(BankAccount* account)
{
    printf("==================================change account status===================================\n");
	printf("\nCurrent Account Status: %s", account->Account_Status);
	printf("\nEnter the new Status(Active/ Restricted):");
	
	char status[100];
	scanf("%s", status);

	strcpy(account->Account_Status, status);
	printf("%s", account->Account_Status);


//////////////////////////////////////////////////////////////////////////////////
////////////////didn't work
	List_voidReplaceBYID(account->BankAccountID , &L, *account);

	BankAccount* client;
	List_voidRetriveBYID(account->BankAccountID ,&L , client);

	printf("%s", client->name);
	printf("%s", client->Account_Status);

	
	printf("Accpunt status successfully changed");




}

void GetCash()
{
    printf(" Get Cash\n");
}

void Deposit()
{
    printf("Deposit\n");
}