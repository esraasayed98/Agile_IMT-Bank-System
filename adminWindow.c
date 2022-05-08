#include <stdio.h>
#include <stdlib.h>

/*************************************************/
/*       Agile Software Development Project      */
/*       Description: Admin Window                */
/*       Date:9 May 2022                         */
/*       Version: v01                            */
/*************************************************/


int validate_username_password(char username[], char password[]){
	return 1;
}

int create_new_account(){
	system("cls");
	char details[20];
	printf("Enter account details: ");
	scanf("%s", &details);
	printf("Hoooorraaaay! account created!");
	return 1;
}

void open_existing_account(int account_id){
	system("cls");
	printf("Account opened!");
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
	}
	else if(choice == 2){
		int account_id;
		printf("Enter account id: ");
		scanf("%d", &account_id);
		open_existing_account(account_id);
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

int main(int argc, char *argv[]) {
	
	int fail = display_login();
	
	while(fail){
		display_login();
	}
	
	display_admin_window();
	return 0;
}
