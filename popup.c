#include<stdlib.h>
#include<stdio.h>
#include "ListLinkedBased.h"
#include <string.h>


int main()
{
    /*declaring str and make the user input its' string*/
    int  Bank_Account_ID;

    Client Element, Element3;

    strcpy(Element.Full_Name ,"Mahmoud Hassan Mohamed Mahmoud");
    strcpy(Element.Full_Adreess ,"A 15 st");
    Element.Age = 24;
    Element.Account_Status = Active;
    Element.Balance = 25000;
    Element.Bank_Account_ID = 0;
    strcpy(Element.Guardian ,"");
    strcpy(Element.Guardian_National_ID, "");
    strcpy(Element.National_ID,"1234567891234");
    strcpy(Element.Password, "123456789");



    Client Element2;

    strcpy(Element2.Full_Name ,"Rames Esam");
    strcpy(Element2.Full_Adreess ,"708090 st");
    Element2.Age = 24;
    Element2.Account_Status = Restricted;
    Element2.Balance = 25000;
    Element2.Bank_Account_ID = 1;
    strcpy(Element2.Guardian ,"");
    strcpy(Element2.Guardian_National_ID, "");
    strcpy(Element2.National_ID,"1234567891234");
    strcpy(Element2.Password, "123456789");

    Client Element4;

    strcpy(Element4.Full_Name ,"Esraa Sayed");
    strcpy(Element4.Full_Adreess ,"A 1305 st");
    Element4.Age = 24;
    Element4.Account_Status = Closed;
    Element4.Balance = 25000;
    Element4.Bank_Account_ID = 2;
    strcpy(Element4.Guardian ,"");
    strcpy(Element4.Guardian_National_ID, "");
    strcpy(Element4.National_ID,"1234567891234");
    strcpy(Element4.Password, "123456789");





    // insert three clients to the list
    List L;
    List_voidInsertList(Element.Bank_Account_ID,&L,Element);
    List_voidInsertList(Element2.Bank_Account_ID,&L,Element2);
    List_voidInsertList(Element4.Bank_Account_ID,&L,Element4);




    // retrive elements of two clients
    printf("please input Account_ID  :  ");
    scanf("%d",&Bank_Account_ID);

    List_voidRetriveList(Bank_Account_ID,&L,&Element3);

     printf("\n data of this bank account bank id : ");
    printf("%s\n", Element3.Full_Name);
    printf("%s\n", Element3.Full_Adreess);
    printf("%d\n", Element3.Age);
    printf("%s\n", Element3.National_ID);
    printf("%d\n", Element3.Balance);

    printf("please input Account_ID  :  ");
    scanf("%d",&Bank_Account_ID);

    List_voidRetriveList(Bank_Account_ID,&L,&Element3);
    


    printf("\n data of this bank account bank id : ");
    printf("%s\n", Element3.Full_Name);
    printf("%s\n", Element3.Full_Adreess);
    printf("%d\n", Element3.Age);
    printf("%s\n", Element3.National_ID);
    printf("%d\n", Element3.Balance);
}