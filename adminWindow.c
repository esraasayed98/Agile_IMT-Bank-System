/*************************************************/
/*       Agile Software Development Project      */
/*       Description: Admin Window                */
/*       Date:9 May 2022                         */
/*       Version: v01                            */
/*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "BankAccount.h"
// #include <conio.h>




void display_login();
int validate_username_password(char username[], char password[]);
int create_new_account();
void open_existing_account();
void display_admin_window();

void Menu(BankAccount* account);
void Operation(int operation,BankAccount* account);
void changeAccountStatus(BankAccount* account);
void MakeTransaction(BankAccount* account);
void GetCash(BankAccount* account);
void Deposit(BankAccount* account);


int main(int argc, char *argv[]) {


	//clients data
	AccountsInit();

	//admin data
	AdminInit();


	display_login();
	
	
	return 0;
}




int validate_username_password(char username[], char password[]){
	AdminListNode * temp = LA.Head;

	while(temp){
		if(strcmp(temp->Data.username, username) == 0 && strcmp(temp->Data.password, password) == 0){
			return 1;
		}
		temp = temp->Next;
		
	}

	return 0;
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


void display_admin_window(){
	system("cls");
	int choice;
	printf("1. Create new account.\n");
	printf("2. Open existing account.\n");
	printf("3. Exit.\n");
	printf("\n Enter your choice: ");
	scanf("%d", &choice);
	
	if(choice == 3 ){
		exit(0);
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



void display_login(){
	
	char username[20];
	char password[16];
	printf("Enter username: ");
	scanf("%s", username);
	printf("\n");
	printf("Enter password: ");
	//scanf("%s", password);
	//display hidden password

    int i=0;

    char ch;

    for(i=0;i<10;i++){
  		ch = getch();
  		password[i] = ch;
  		ch = '*' ;
  		printf("%c",ch);
    } 

	if (validate_username_password(username, password)){
		display_admin_window();
	}
	else{
		system("cls");
		printf("Wrong username or password, try again.\n");
		display_login();
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
            MakeTransaction(account);
            // Menu();
            break;
        case 2:
            changeAccountStatus(account);
            // Menu();
            break;
        case 3 :
            GetCash(account);
            // Menu();
            break;
        case 4:
            Deposit(account);
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





void MakeTransaction(BankAccount* account)
{
	system("cls");

    //check account status 
	int value;
	value=strcmp(account->Account_Status,"Active");  
	if ( value== 0)
	{


		printf("==========================================================================================\n");
    	printf("==============================Make Transaction ===========================================\n");
    
		printf("Enter the Account ID you want to transfer to :");
		BankAccount client;
		long long int Bank_Account_ID;
		scanf("%lld",&Bank_Account_ID);
		List_voidRetriveBYID(Bank_Account_ID,&L,&client);

		printf("Enter amount of money:");
		long long int Money;
		scanf("%lld", &Money);

		//check balance
		if (account->Balance< Money)
		{
			printf("Sorry can't perform the Transaction because your balance is less than the money you want to transfer");
			printf("\nYour Balance: %lld", account->Balance);
		}
		else{
			//check if the account is active
			int value2;
			value2=strcmp(client.Account_Status,"Active");  
			if (value2==0)
			{
				client.Balance+=Money;
				account->Balance-=Money;
				
				List_voidReplaceBYID(account->BankAccountID , &L, *account);
				List_voidReplaceBYID(client.BankAccountID , &L, client);



				//check
				BankAccount client1, client2;
				List_voidRetriveBYID(account->BankAccountID ,&L , &client1);
				List_voidRetriveBYID(client.BankAccountID ,&L , &client2);

				
				printf("\nYour New Balance  %lld", client1.Balance);


				printf("\n Client Name: %s", client2.name);
				printf("\nNew Balance  %lld", client2.Balance);

				

				printf("\nTransaction is done Successfully");


			}
			else{
				printf("\nAccount to transfer to is Restricted you can't make transaction to it!!");
		}
		}


		

	}
	else
	{
		printf("\nAccount is Restricted You can't make a Transaction!!");
	}

   


	

	
}

void changeAccountStatus(BankAccount* account)
{
	printf("==========================================================================================\n");
    printf("==============================change account status=======================================\n");

	printf("\nCurrent Account Status: %s", account->Account_Status);
	printf("\nEnter the new Status(Active/ Restricted):");
	
	char status[100];
	scanf("%s", status);

	strcpy(account->Account_Status, status);
	// printf("%s", account->Account_Status);


	List_voidReplaceBYID(account->BankAccountID , &L, *account);

	//check
	BankAccount client;
	List_voidRetriveBYID(account->BankAccountID ,&L , &client);

	printf("\n%s", client.name);
	printf("\n%s", client.Account_Status);

	
	printf("\n status successfully changed");




}

void GetCash(BankAccount* account)
{
	printf("==========================================================================================\n");
    printf("================================Get Cach==================================================\n");

	int value;
	value=strcmp(account->Account_Status,"Active");  
	if ( value== 0)
	{

		printf("Enter amount of money:");
		long long int Money;
		scanf("%lld", &Money);

		//check balance
		if (account->Balance< Money)
		{
			printf("Sorry can't perform the Transaction because your balance is less than the money you entered");
			printf("\nYour Balance: %lld", account->Balance);
		}
		else{
			
			account->Balance-=Money;
			
			List_voidReplaceBYID(account->BankAccountID , &L, *account);


			//check updates in the linked list
			BankAccount client1;
			List_voidRetriveBYID(account->BankAccountID ,&L , &client1);
			
			printf("\nYour New Balance:  %lld", client1.Balance);


			printf("\nTransaction is done Successfully");


			}

		}


	else
	{
		printf("\nAccount is Restricted You can't make a Transaction!!");
	}

    
}

void Deposit(BankAccount* account)
{
	printf("==========================================================================================\n");
    printf("================================Deposit in Account========================================\n");
	int value;
	value=strcmp(account->Account_Status,"Active");  
	if ( value== 0)
	{

		printf("Enter amount of money:");
		long long int Money;
		scanf("%lld", &Money);

		
			
		account->Balance+=Money;
		
		List_voidReplaceBYID(account->BankAccountID , &L, *account);


		//check updates in the linked list
		BankAccount client1;
		List_voidRetriveBYID(account->BankAccountID ,&L , &client1);
		
		printf("\nYour New Balance:  %lld", client1.Balance);

		printf("\nDeposit is added in Account Successfully");


	}
	else
	{
		printf("\nAccount is Restricted You can't make a Transaction!!");
	}

    
}