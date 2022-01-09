/*A program to implement a linear queue using linked list with related functions*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct record
{
    int value;
    struct record *next;
}QUEUENODE;

QUEUENODE *front=NULL,*rear=NULL;

void prompt()
{
    printf("\n------------------------------------------------------------");
    printf("\n|| Press <1> to insert data into the queue                ||");
    printf("\n|| Press <2> to delete data from the queue                ||");
    printf("\n|| Press <3> to check if the queue will Underflow or not  ||");
    printf("\n|| Press <4> to display the queue                         ||");
    printf("\n|| Press <0> to exit                                      ||");
    printf("\n------------------------------------------------------------");
}

int isEmpty()
{
    if(front==NULL)
        return 1;
    else
        return 0;
}

void insert(int val)
{
	QUEUENODE *temp;
	temp=(QUEUENODE*)malloc(sizeof(QUEUENODE));
    temp->value=val;
    temp->next=NULL;
    if(rear==NULL)
    {
        front=temp;
    	rear=temp;
    }
    else
    {
    	rear->next=temp;
    	rear=rear->next;
	}
}

int delete()
{
    int val;
	QUEUENODE *temp;
    if(isEmpty())
    {
        puts("\n!!! Queue Underflow !!!");
        return INT_MIN;
    }
    val=front->value;
    temp=front;
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
        front=front->next;
    free(temp);
    
    return val;
}

void display()
{
	QUEUENODE *temp;
    if(isEmpty())
        puts("!!! Queue Underflow !!!");
    else
    {
    	temp=front;
		while(temp!=NULL)
        {
            printf("%d\n",temp->value);
            temp=temp->next;
        }
    }
}

int main()
{
	int val,choice,x;
    do
    {
        prompt();
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
            case 1: printf("Enter the value to insert: ");
	                scanf("%d",&val);
                    insert(val);
	                puts("Current queue...");
                    display();
                    break;
            case 2: x=delete();
                    if(x!=INT_MIN)
                        printf("Deleted data: %d\n",x);
                    break;
            case 3: if(isEmpty())
                        puts("!!! Queue Underflow !!!");
                    else
                        puts("Elements are present in queue...");
                    break;
            case 4: puts("Current queue...");
                    display();
                    break;
            default: puts("\nPlease enter correct choice...");
        }
    }while(choice!=0);

    return 0;
}
/*

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to check if the stack will Underflow or not  ||
|| Press <4> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to push: 1
Current stack...
1

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to check if the stack will Underflow or not  ||
|| Press <4> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to push: 2
Current stack...
2
1

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to check if the stack will Underflow or not  ||
|| Press <4> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to push: 3
Current stack...
3
2
1

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to check if the stack will Underflow or not  ||
|| Press <4> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 2
Popped data: 3

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to check if the stack will Underflow or not  ||
|| Press <4> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 3
Elements are present in stack...

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to check if the stack will Underflow or not  ||
|| Press <4> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 4
Current stack...
2
1

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to check if the stack will Underflow or not  ||
|| Press <4> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 0
*/