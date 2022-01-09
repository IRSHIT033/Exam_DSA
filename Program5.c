/*A program to implement a circular queue using array with related functions*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int front=0,rear=0;

void prompt()
{
    printf("\n------------------------------------------------------------");
    printf("\n|| Press <1> to store data into the queue                 ||");
    printf("\n|| Press <2> to retrieve data from the queue              ||");
    printf("\n|| Press <3> to check if the queue will Overflow or not   ||");
    printf("\n|| Press <4> to check if the queue will Underflow or not  ||");
    printf("\n|| Press <5> to display the queue                         ||");
    printf("\n|| Press <0> to exit                                      ||");
    printf("\n------------------------------------------------------------");
}

int isFull(int n)
{
    if((rear+1)%n==front)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(front==rear)
        return 1;
    else
        return 0;
}

void store(int n, int *queue, int value)
{
    if(isFull(n))
    {
        puts("\n!!! Queue Overflow !!!");
        return;
    }
    rear=(rear+1)%n;
    queue[rear]=value;
}

int retrieve(int n, int *queue)
{
    int value;
    if(isEmpty())
    {
        puts("\n!!! Queue Underflow !!!");
        return INT_MIN;
    }
    front=(front+1)%n;
    value=queue[front];

    return value;
}

void display(int n, int *queue)
{
    int i;
    if(isEmpty())
        puts("\n!!! Queue Underflow !!!");
    else
    {
        for(i=(front+1)%n;i!=rear;i=(i+1)%n)
            printf("%d\t",queue[i]);
        printf("%d\t",queue[i]);
    }
}

int main()
{
    int n,val,choice,x;
	printf("Enter the size of the queue: ");
	scanf("%d",&n);
    n++;
    int queue[n];
    do
    {
        prompt();
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
            case 1: printf("Enter the value to store: ");
	                scanf("%d",&val);
                    store(n,queue,val);
	                puts("Current queue...");
                    display(n,queue);
                    break;
            case 2: x=retrieve(n,queue);
                    if(x!=INT_MIN)
                        printf("Retrieved data: %d\n",x);
                    break;
            case 3: if(isFull(n)==1)
                        puts("!!! Queue Overflow !!!");
                    else
                        puts("Queue space is available...");
                    break;
            case 4: if(isEmpty()==1)
                        puts("!!! Queue Underflow !!!");
                    else
                        puts("Elements are present in queue...");
                    break;
            case 5: puts("Current queue...");
                    display(n,queue);
                    break;
            default: puts("\nPlease enter correct choice...");
        }
    }while(choice!=0);

    return 0;
}
/*

------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to store: 1
Current queue...
1
------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to store: 2
Current queue...
1       2
------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to store: 3
Current queue...
1       2       3
------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to store: 4
Current queue...
1       2       3       4
------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to store: 5

!!! Queue Overflow !!!
Current queue...
1       2       3       4
------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 2
Retrieved data: 1

------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 5
Current queue...
2       3       4
------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 1
Enter the value to store: 5
Current queue...
2       3       4       5
------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 2
Retrieved data: 2

------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 5
Current queue...
3       4       5
------------------------------------------------------------
|| Press <1> to store data into the queue                 ||
|| Press <2> to retrieve data from the queue              ||
|| Press <3> to check if the queue will Overflow or not   ||
|| Press <4> to check if the queue will Underflow or not  ||
|| Press <5> to display the queue                         ||
|| Press <0> to exit                                      ||
------------------------------------------------------------
Enter choice: 0
*/
