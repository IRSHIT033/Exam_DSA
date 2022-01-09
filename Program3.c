/*A program to implement a stack using array with related functions*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define SIZE 5

int top=-1;
int stack[SIZE];

void prompt()
{
    printf("\n------------------------------------------------------------");
    printf("\n|| Press <1> to push data into the stack                  ||");
    printf("\n|| Press <2> to pop data from the stack                   ||");
    printf("\n|| Press <3> to view the current topmost stack data       ||");
    printf("\n|| Press <4> to check if the stack will Overflow or not   ||");
    printf("\n|| Press <5> to check if the stack will Underflow or not  ||");
    printf("\n|| Press <6> to display the stack                         ||");
    printf("\n|| Press <0> to exit                                      ||");
    printf("\n------------------------------------------------------------");
}

int isFull()
{
    if(top==SIZE-1)
        return true;
    else
        return false;
}

int isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}

void push(int value)
{
    if(isFull())
        puts("!!! Stack Overflow !!!");
    else
        stack[++top]=value;
}

int pop()
{
    if(isEmpty())
    {
        puts("!!! Stack Underflow !!!");
        return INT_MIN;
    }
    else
        return stack[top--];
}

int peek()
{
    if(isEmpty())
    {
        puts("!!! Stack Underflow !!!");
        return INT_MIN;
    }
    else
        return stack[top];
}

void display()
{
    int i;
    if(isEmpty())
        puts("!!! Stack Underflow !!!");
    else
        for(i=top;i>=0;i--)
            printf("%d\n",stack[i]);
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
            case 3: x=peek();
                    if(x!=INT_MIN)
                        printf("Current topmost stack data: %d\n",x);
                    break;
            case 4: if(isFull())
                        puts("!!! Stack Overflow !!!");
                    else
                        puts("Stack space is available...");
                    break;
            case 5: if(isEmpty())
                        puts("!!! Stack Underflow !!!");
                    else
                        puts("Elements are present in stack...");
                    break;
            case 6: puts("Current stack...");
                    display();
                    break;
            default: puts("\nPlease enter correct choice...");
        }
    }while(choice!=0);

    return 0;
}
/**
 * 
------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to view the current topmost stack data       ||
|| Press <4> to check if the stack will Overflow or not   ||
|| Press <5> to check if the stack will Underflow or not  ||
|| Press <6> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to push: 1
Current stack...
1

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to view the current topmost stack data       ||
|| Press <4> to check if the stack will Overflow or not   ||
|| Press <5> to check if the stack will Underflow or not  ||
|| Press <6> to display the stack                         ||
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
|| Press <3> to view the current topmost stack data       ||
|| Press <4> to check if the stack will Overflow or not   ||
|| Press <5> to check if the stack will Underflow or not  ||
|| Press <6> to display the stack                         ||
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
|| Press <3> to view the current topmost stack data       ||
|| Press <4> to check if the stack will Overflow or not   ||
|| Press <5> to check if the stack will Underflow or not  ||
|| Press <6> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 3
Current topmost stack data: 3

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to view the current topmost stack data       ||
|| Press <4> to check if the stack will Overflow or not   ||
|| Press <5> to check if the stack will Underflow or not  ||
|| Press <6> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 4
Stack space is available...

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to view the current topmost stack data       ||
|| Press <4> to check if the stack will Overflow or not   ||
|| Press <5> to check if the stack will Underflow or not  ||
|| Press <6> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 5
Elements are present in stack...

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to view the current topmost stack data       ||
|| Press <4> to check if the stack will Overflow or not   ||
|| Press <5> to check if the stack will Underflow or not  ||
|| Press <6> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 6
Current stack...
3
2
1

------------------------------------------------------------
|| Press <1> to push data into the stack                  ||
|| Press <2> to pop data from the stack                   ||
|| Press <3> to view the current topmost stack data       ||
|| Press <4> to check if the stack will Overflow or not   ||
|| Press <5> to check if the stack will Underflow or not  ||
|| Press <6> to display the stack                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 0
 * 
 */
