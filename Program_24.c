/*A program to implement a doubly linked list with related functions*/

#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    struct record *prev;    
    int value;
    struct record *next;
}NODE;

NODE *start=NULL;

void prompt()
{
    printf("\n-----------------------------------------------------------------");
    printf("\n|| Press <1> to add a new node at beginnning of list           ||");
    printf("\n|| Press <2> to add a new node to the list                     ||");
    printf("\n|| Press <3> to delete a node from the beginning of the list   ||");
    printf("\n|| Press <4> to delete the last node of the list               ||");
    printf("\n|| Press <5> to display the list                               ||");
    printf("\n|| Press <0> to exit                                           ||");
    printf("\n-----------------------------------------------------------------");
}

void add_begin(int data)
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->value=data;
    temp->prev=NULL;
    temp->next=start;
    if(start!=NULL)
        start->prev=temp;
    start=temp;
}

void append(int data)
{
    NODE *temp,*curr;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->value=data;
    temp->next=NULL;
    if(start==NULL)
    {
        printf("\nFirst node of the list created...");
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        curr=start;
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=temp;
        temp->prev=curr;
    }
}

void del_begin()
{
    NODE *temp=start;
    if(temp==NULL)
    {
        printf("!!! Empty list !!!");
        return;
    }
    start=start->next;
    start->prev=NULL;
    printf("\nDeleted value: %d",temp->value);
    free(temp);
}

void del_last()
{
    NODE *curr=start;
    if(curr==NULL)
    {
        printf("!!! Empty list !!!");
        return;
    }
    while(curr->next!=NULL)
        curr=curr->next;
    curr->prev->next=NULL;
    printf("\nDeleted value: %d",curr->value);
    free(curr);
}

void display()
{
    int count=0;
    NODE* curr=start;
    printf("\nCurrent list...\n");
    if(curr==NULL)
        printf("!!! Empty list !!!");
    while(curr!=NULL)
    {
        printf("\nData %d: %d",++count,curr->value);
        curr=curr->next;
    }
}

void end()
{
    while(start!=NULL)
        del_begin();
}

int main()
{
    int choice,data,num,pos;
    do
    {
        prompt();
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: end();
                    break;
            case 1: printf("\nEnter data: ");
                    scanf("%d",&data);
                    add_begin(data);
                    break;
            case 2: printf("\nEnter data: ");
                    scanf("%d",&data);
                    append(data);
                    break;
            case 3: del_begin();
                    break;
            case 4: del_last();
                    break;
            case 5: display();
                    break;
            default: printf("\nEnter a valid choice...");
        }
    }
    while(choice!=0);

    return 0;
}
/*
-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 1

Enter data: 1

-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 2

Enter data: 4

-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 5

Current list...

Data 1: 1
Data 2: 4
-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 3

Deleted value: 1
-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 4
*/