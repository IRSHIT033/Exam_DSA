/*A program to implement a stack using linked list with related functions*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct record
{
    int value;
    struct record *next;
}STACKNODE;

STACKNODE *top=NULL;
int count=0;

void prompt()
{
    printf("\n------------------------------------------------------------");
    printf("\n|| Press <1> to push data into the stack                  ||");
    printf("\n|| Press <2> to pop data from the stack                   ||");
    printf("\n|| Press <3> to check if the stack will Underflow or not  ||");
    printf("\n|| Press <4> to display the stack                         ||");
    printf("\n|| Press <0> to exit                                      ||");
    printf("\n------------------------------------------------------------"); 
}

int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(int val)
{
    STACKNODE *temp;
    temp=(STACKNODE*)malloc(sizeof(STACKNODE));
    temp->value=val;
    temp->next=top;
    top=temp;
    count++;
}

int pop()
{
    STACKNODE *temp;
    int val;
    if(isEmpty())
    {
        puts("!!! Stack Underflow !!!");
        return INT_MIN;
    }
    val=top->value;
    temp=top;
    top=top->next;
    free(temp);
    count--;

    return val;
}

void display()
{
    STACKNODE *temp;
    if(isEmpty())
        puts("!!! Stack Underflow !!!");
    else
    {
        temp=top;
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
            case 0: break;
            case 1: printf("Enter the value to push: ");
	                scanf("%d",&val);
                    push(val);
	                puts("Current stack...");
                    display();
                    break;
            case 2: x=pop();
                    if(x!=INT_MIN)
                        printf("Popped data: %d\n",x);
                    break;
            case 3: if(isEmpty())
                        puts("!!! Stack Underflow !!!");
                    else
                        puts("Elements are present in stack...");
                    break;
            case 4: puts("Current stack...");
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
Enter choice: 0*/