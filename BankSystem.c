
/*************************************************/
/*       Agile Software Development Project      */
/*       Description: Bank System                */
/*       Date:10 May 2022                         */
/*       Version: v01                            */
/*************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "adminWindow.h"


/**************************************************/
/***************Functions Prototypes***************/
/**************************************************/

void Welcomepage();

int main()
{
    Welcomepage();

    return 0;
}

void Welcomepage()
{
    system("cls");
    
    printf("\n ********************************************************************************************************************\n");
    printf("\n                                             Welcom to IMT Bank System                                               \n");
    printf("\n ********************************************************************************************************************\n");
    

    printf("\n  1. Admin ");
    printf("\n  2.Client ");

    printf("\n\n  Select from the options:");
    int op;
    scanf("%d",&op);
    // printf("%d",op);
   
   if (op==1)
   {
        system("cls");
        printf("\n ********************************************************************************************************************\n");
        printf("\n                                             Admin Log in page                                                      \n");
        printf("\n ********************************************************************************************************************\n\n");
        

       //Admins data

       //clients data
	    AccountsInit();
        int fail = display_login();
        while(fail){
		display_login();
        }
        
        display_admin_window();

   }
   else
   {
       if(op == 2)
       {
           //user's page
            system("cls");
            printf("\n ********************************************************************************************************************\n");
            printf("\n                                             Client Log in page                                                      \n");
            printf("\n ********************************************************************************************************************\n\n");
        
       }
    //    else
   }
  

}