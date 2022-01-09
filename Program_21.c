/*A program to implement a singly linked list with related functions*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct record
{
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
    temp->next=start;
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
        start=temp;
    }
    else
    {
        curr=start;
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=temp;
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
    printf("\nDeleted value: %d",temp->value);
    free(temp);
}

void del_last()
{
    NODE *curr=start,*temp;
    if(curr==NULL)
    {
        printf("!!! Empty list !!!");
        return;
    }
    while(curr->next->next!=NULL)
        curr=curr->next;
    temp=curr->next;
    curr->next=NULL;
    printf("\nDeleted value: %d",temp->value);
    free(temp);
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

void search(int data)
{
    NODE *curr=start;
    int count=0;
    bool check=false;
    while(curr!=NULL)
    {
        count++;
        if(curr->value==data)
        {
			printf("\n%d present in position: %d",data,count);
            check=true;
        }
        curr=curr->next;
    }
    if(check==false)
		printf("\n!!! %d not present in the list !!!",data);
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

Enter data: 2

-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 2

Enter data: 3

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
Data 2: 2
Data 3: 3
Data 4: 4
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
Enter choice: 5

Current list...

Data 1: 2
Data 2: 3
Data 3: 4
-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 4

Deleted value: 4
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

Data 1: 2
Data 2: 3
-----------------------------------------------------------------
|| Press <1> to add a new node at beginnning of list           ||
|| Press <2> to add a new node to the list                     ||
|| Press <3> to delete a node from the beginning of the list   ||
|| Press <4> to delete the last node of the list               ||
|| Press <5> to display the list                               ||
|| Press <0> to exit                                           ||
-----------------------------------------------------------------
Enter choice: 0

Deleted value: 2
Deleted value: 3
*/