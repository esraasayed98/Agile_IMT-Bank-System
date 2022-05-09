/****************************************************/
/*   AUTHOR      : Mahmoud Hassan Mohamed Mahmoud   */
/*   Description : ListLinkedBased                  */
/*   DATE        : 28 Dec 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

#include<stdlib.h>
#include<stdio.h>

enum AC_status{Active, Restricted, Closed};


typedef struct client{
    char  Full_Name[100];
    char  Full_Adreess[100];
    char  National_ID[14];
    int   Age;
    int  Bank_Account_ID;
    char  Guardian[100];
    char  Guardian_National_ID[14];
    enum  AC_status Account_Status;
    int Balance;
    char  Password[100];

}Client;

typedef struct listnode{
    Client  Data;
    struct listnode * Next;

}ListNode;

typedef struct ListLinkedBased
{
    ListNode * Head;
    int Size;
}List;


/***********************************************************************/
/****************************Functions Prototypes***********************/
/***********************************************************************/


void List_voidInit(List *pl);
void List_voidInsertList(int Position, List *pl, Client Element);
void List_voidReplaceList(int Position, List *pl, Client Element);
void List_voidDeleteList(int Position, List *pl, Client * Element);
void List_voidRetriveList(int Position, List *pl, Client * Element);
int  List_intIsEmpty(List *pl);
int  List_intIsFull(List *pl);
int  List_intSize(List *pl);
// void List_voidPrintList(List*pl);
void List_voidDestroyList(List *pl);



/***********************************************************************/
/****************************Functions Implementations******************/
/***********************************************************************/

void List_voidInit(List *pl){
    pl->Head = NULL;
    pl->Size = 0;
}


void List_voidInsertList(int Position, List *pl, Client  Element){
    /*create new node and intialize its data*/
    ListNode* pn = (ListNode *)malloc(sizeof(ListNode));
    pn->Data = Element;

    /*corner case : insertion in the first plcae*/
    if (Position == 0){
        pn->Next = pl->Head;
        pl->Head = pn;
    }

    /*General case : Insert in any position instead of position 0*/
    else{
        /*create a new pointer of list node and iterate until reaching the position before that i want*/
        ListNode * pn2 = pl->Head;
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


void List_voidReplaceList(int Position, List *pl, Client Element){
    /*create a new pointer of list node and iterate until reaching the position that i want*/
    ListNode * pn = pl->Head;
    for(int i = 0; i < Position-1; i++ ){
        pn = pn->Next;
    }

    /*return the data that i want*/
    pn->Data = Element;
}


void List_voidDeleteList(int Position, List *pl, Client * Element){
    ListNode * pn = pl->Head;

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
        ListNode * pn2 = pl->Head;
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


void List_voidRetriveList(int Position, List *pl, Client * Element){
    ListNode * pn = pl->Head;
    for(int i = 0; i < Position; i++ ){
        pn = pn->Next;
    }
    *Element = pn->Data;
}

int  List_intIsEmpty(List *pl){
    return pl->Head == NULL;
}

int  List_intIsFull(List *pl){
    return 0;
}

int  List_intSize(List *pl){
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
void List_voidDestroyList(List *pl){
    ListNode *pn = pl->Head;

    while(pl->Head != NULL)
    {
        pn = pn->Next;
        free(pl->Head);
        pl->Head = pn;
    }

    pl->Size =0;
}

