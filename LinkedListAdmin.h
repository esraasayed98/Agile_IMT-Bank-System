/****************************************************/
/*   AUTHOR      : Ramez Essam                      */
/*   Description : AdminListLinkedBased             */
/*   DATE        : 28 Dec 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>




typedef struct admin
{
    char username[100];
	char password[100];
    

    
}Admin;

typedef struct adminlistnode{
    Admin  Data;
    struct adminlistnode * Next;

}AdminListNode;

typedef struct adminListLinkedBased
{
    AdminListNode * Head;
    int Size;
}AdminList;


/***********************************************************************/
/****************************Functions Prototypes***********************/
/***********************************************************************/


void AdminList_voidInit(AdminList *pl);
void AdminList_voidInsertList(int Position, AdminList *pl, Admin Element);
void AdminList_voidReplaceList(int Position, AdminList *pl, Admin Element);
void AdminList_voidDeleteList(int Position, AdminList *pl, Admin * Element);
void AdminList_voidRetriveList(int Position, AdminList *pl, Admin * Element);
int  AdminList_intIsEmpty(AdminList *pl);
int  AdminList_intIsFull(AdminList *pl);
int  AdminList_intSize(AdminList *pl);
// void List_voidPrintList(List*pl);
void AdminList_voidDestroyList(AdminList *pl);

void AdminList_voidReplaceBYID(long long int ID, AdminList *pl, Admin Element);

/***********************************************************************/
/****************************Functions Implementations******************/
/***********************************************************************/

void AdminList_voidInit(AdminList *pl){
    pl->Head = NULL;
    pl->Size = 0;
}


void AdminList_voidInsertList(int Position, AdminList *pl, Admin  Element){
    /*create new node and intialize its data*/
    AdminListNode* pn = (AdminListNode *)malloc(sizeof(AdminListNode));
    pn->Data = Element;

    /*corner case : insertion in the first plcae*/
    if (Position == 0){
        pn->Next = pl->Head;
        pl->Head = pn;
    }

    /*General case : Insert in any position instead of position 0*/
    else{
        /*create a new pointer of list node and iterate until reaching the position before that i want*/
        AdminListNode * pn2 = pl->Head;
        for(int i = 0; i < Position-1; i++ ){
            pn2 = pn2->Next;
        }
        /*Insertion Step*/
        pn->Next = pn2->Next;
        pn2->Next = pn;

    }
    /*increasing the size of the list*/
    pl->Size++;
}


void AdminList_voidReplaceList(int Position, AdminList *pl, Admin Element){
    /*create a new pointer of list node and iterate until reaching the position that i want*/
    AdminListNode * pn = pl->Head;
    for(int i = 0; i < Position-1; i++ ){
        pn = pn->Next;
    }

    /*return the data that i want*/
    pn->Data = Element;
}


void AdminList_voidReplaceBYusername(char * username, AdminList *pl, Admin Element){
    
    AdminListNode * pn = pl->Head;

    if(strcmp(username, pn->Data.username) == 0){
        strcpy(pn->Data.username, username);
    }

    
    pn->Data = Element;
}


void AdminList_voidDeleteList(int Position, AdminList *pl, Admin * Element){
    AdminListNode * pn = pl->Head;

    /*corner case : Deletion from the first plcae*/
    if (Position == 0){
        /*return the data that i want*/
        *Element = pl->Head->Data;
        
        /*Deletion Steps*/
        pn= pl->Head->Next;
        free(pl->Head);
        pl->Head = pn->Next;

    }
    /*General case : Deletion from any position instead of position 0*/
    else{
        /*create a new pointer of list node and iterate until reaching the position before that i want*/
        AdminListNode * pn2 = pl->Head;
        for(int i = 0; i < Position-1; i++ ){
            pn2 = pn2->Next;
        }
        /*return the data that i want*/
        *Element = pn2->Next->Data;

        /*Deletion Steps*/
        pn = pn2->Next->Next;
        free(pn2->Next);
        pn2->Next = pn;

    }
    /*Decreasing the Size*/
    pl->Size--;
}


void AdminList_voidRetriveList(int Position, AdminList *pl, Admin * Element){
    AdminListNode * pn = pl->Head;
    for(int i = 0; i < Position; i++ ){
        pn = pn->Next;
    }
    *Element = pn->Data;
}

void AdminList_voidRetriveBYusername(char * username, AdminList *pl, Admin * Element){

    AdminList *pl_temp = pl;
    

    while(pl_temp->Head){
        AdminListNode * pn = pl_temp->Head;
        if(strcmp(username, pl_temp->Head->Data.username) == 0){
        *Element = pn->Data;
        }
        


    }
 
}


int  AdminList_intIsEmpty(AdminList *pl){
    return pl->Head == NULL;
}

int  AdminList_intIsFull(AdminList *pl){
    return 0;
}

int  AdminList_intSize(AdminList *pl){
    return pl->Size;
}

// void List_voidPrintList(List*pl){
//     ListNode* q= pl->Head;
//     while(q != NULL)
//     {
//         printf("%d\t", q->Data);
//         q= q->Next;
//     }
// }
void AdminList_voidDestroyList(AdminList *pl){
    AdminListNode *pn = pl->Head;

    while(pl->Head != NULL)
    {
        pn = pn->Next;
        free(pl->Head);
        pl->Head = pn;
    }

    pl->Size =0;
}

