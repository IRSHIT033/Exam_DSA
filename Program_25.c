/*A program to implement a circular singly linked list with related functions*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct record
{
    struct record *prev;    
    int value;
    struct record *next;
}NODE;

NODE *last=NULL;

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
    if(last==NULL)
    {
        last=temp;
        last->next=last;
    }
    else
    {
        temp->next=last->next;
        last->next=temp;
    }
}

void append(int data)
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->value=data;
    if(last==NULL)
    {
        printf("\nFirst node of the list created...");
        last=temp;
        last->next=last;
    }
    else
    {
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
}

void del_begin()
{
    NODE *temp=last;
    if(temp==NULL)
    {
        printf("!!! Empty list !!!");
        return;
    }
    else if(temp->next==temp)
    {
    	free(last);
    	last=NULL;
    	return;
	}
    temp=last->next;
    last->next=temp->next;
    printf("\nDeleted value: %d",temp->value);
    free(temp);
}

void del_last()
{
    NODE *curr=last,*temp;
    if(curr==NULL)
        printf("!!! Empty list !!!");
    else if(last->next==last)
    {
        printf("\nDeleted value: %d",last->value);
        last=NULL;
        free(last);
    }
    else
    {
        curr=last;
        while(last->next!=curr)
            last=last->next;
        last->next=curr->next;
        printf("\nDeleted value: %d",curr->value);
        free(curr);
    }
}

void display()
{
    int count=0;
    NODE* curr=last;
    printf("\nCurrent list...\n");
    if(curr==NULL)
    {
        printf("!!! Empty list !!!");
        return;
    }
    curr=last->next;
    do
    {
        printf("\nData %d: %d",++count,curr->value);
        curr=curr->next;
    }while(curr!=last->next);
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
            case 0: exit(0);
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

Enter data: 20

-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 2

Enter data: 700

-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 2

Enter data: 500

-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 1

Enter data: 300

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

Data 1: 300
Data 2: 20
Data 3: 700
Data 4: 500
-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 4

Deleted value: 500
-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 3

Deleted value: 300
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

Data 1: 20
Data 2: 700
-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 0*/