/*A program to implement a 1-D array with related functions*/

#include <stdio.h>
#include <stdlib.h>

void prompt()
{
    printf("\n------------------------------------------------------------------");
    printf("\n|| Press <1> to update at a position in the array               ||");
    printf("\n|| Press <2> to insert an element at a position in the array    ||");
    printf("\n|| Press <3> to search an element in the array                  ||");
    printf("\n|| Press <4> to delete an element from the array                ||");
    printf("\n|| Press <5> to display the array                               ||");
    printf("\n|| Press <0> to exit                                            ||");
    printf("\n------------------------------------------------------------------");
}

void update(int n, int *array, int value, int position)
{
    if(position>n || position<1)
        printf("\n!!! Invalid position. Array cannot be updated !!!");
    else
        array[position-1]=value;        
}

int insert(int n, int *array, int value, int position)
{
    int i;
    if(position>n || position<1)
        printf("\n!!! Invalid position. Value cannot be inserted !!!");
    else
        for(i=n;i>=position;i--)
            array[i]=array[i-1];
    array[position-1]=value;
    n++;

    return n;
}

int search(int n, int *array, int value)
{
    int i;
    for(i=0;i<=n-1;i++)
	    if(array[i]==value)
	        return i+1;
    
    return -1;
}

int delete(int n, int *array, int value)
{
     int i,j,help_idx;
    for(i=0;i<n;i++)
	{
	 if(array[i]==value){
       help_idx=i;
     }
    }
    for(int j=help_idx;j<n;j++){
        array[j]=array[j+1];
    }
    n--;

    return n;
}

void display(int n, int *array)
{
    int i;
    for(i=0;i<=n-1;i++)
        printf("%d\n",array[i]);
}

int main()
{
	int n,i,j,k,val,pos,choice;
    int *arr;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("\nEnter array elements\n");
    for(i=0;i<=n-1;i++)
        scanf("%d",&arr[i]);
    do
    {
        prompt();
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
            case 1: printf("\nEnter the value and position of the value to update: ");
	                scanf("%d%d",&val,&pos);
                    update(n,arr,val,pos);
	                puts("\nAfter updation...");
                    display(n,arr);
                    break;
            case 2: printf("\nEnter the value and position of the value to insert: ");
	                scanf("%d%d",&val,&pos);
                    n=insert(n,arr,val,pos);
	                puts("\nAfter insertion...");
                    display(n,arr);
                    break;
            case 3: printf("\nEnter the value to search: ");
	                scanf("%d",&val);
                    k=search(n,arr,val);
                    if(k>=0)
                        printf("\n%d present in position: %d",val,k);
                    else
                        printf("\n%d not present in the array !!!",val);
                    break;
            case 4: printf("\nEnter the value to delete: ");
	                scanf("%d",&val);
                    n=delete(n,arr,val);
	                puts("\nAfter deletion...");
                    display(n,arr);
                    break;
            case 5: puts("\nCurrent array...");
                    display(n,arr);
                    break;
            default: puts("\nPlease enter correct choice...");
        }
    }while(prompt!=0);

    return 0;
}
/*
Explaination:-

first We have to a menu driven program to run several array functions
then we should create dynamic array of which will be user Inputted
 -:## In Update function ##:-
      our Update function has four Parameters :-size,array,updated value(user inputted),position(user inputted)
      first we have to check if given position is valid or not,then  assign our updated value to  our given  position (position-1) .
 -:## In Insert function ##:-  
       our Insert function has  four Parameters size,array,desired value(user inputted),position(user inputted)   
       first we have to check if given position is valid or not,then we should traverse through array's last position to desired postion.
       meanwhile We have to updated our current element to its previous element.After traversing we have update our value to out desired postion.
 -:## In Search function ##:-
       our Search function has three parameters:-size,array,value(user inputted).
       We have to traverse the whole array and also check if it's current postion's element is matching with our  value or not.If We dont find our desired value.
       then we returning -1 or if we find it then we have to return the postion where it's found.It will be linear Search.
  -:## In Delete function ##:-
       our delete function has three parameters:-size,array,value(user inputted)  
       first we have to search the element's postion that we want to delete. Then we have to traverse through desired value's position  to arrays's last position
       meanwhile we have to replace current element to its next postion's element. After this we have to decrease the size of our array by 1 then return the new size of the array in our function.
   -:## In Display function ##:-
       our size function has two parameters:- size, array.
       In this function we are traversing and printing the element of the whole Array;
       
*/

/*//////////////////////////////////////////////*/
/**
 * Enter the size of the array: 5

Enter array elements
1 2 3 4 5

------------------------------------------------------------------
|| Press <1> to update at a position in the array               ||
|| Press <2> to insert an element at a position in the array    ||
|| Press <3> to search an element in the array                  ||
|| Press <4> to delete an element from the array                ||
|| Press <5> to display the array                               ||
|| Press <0> to exit                                            ||
------------------------------------------------------------------
Enter choice: 1

Enter the value and position of the value to update: 20 2

After updation...
1
20
3
4
5

------------------------------------------------------------------
|| Press <1> to update at a position in the array               ||
|| Press <2> to insert an element at a position in the array    ||
|| Press <3> to search an element in the array                  ||
|| Press <4> to delete an element from the array                ||
|| Press <5> to display the array                               ||
|| Press <0> to exit                                            ||
------------------------------------------------------------------
Enter choice: 2

Enter the value and position of the value to insert: 30 3

After insertion...
1
20
30
3
4
5

------------------------------------------------------------------
|| Press <1> to update at a position in the array               ||
|| Press <2> to insert an element at a position in the array    ||
|| Press <3> to search an element in the array                  ||
|| Press <4> to delete an element from the array                ||
|| Press <5> to display the array                               ||
|| Press <0> to exit                                            ||
------------------------------------------------------------------
Enter choice: 3

Enter the value to search: 30

30 present in position: 3
------------------------------------------------------------------
|| Press <1> to update at a position in the array               ||
|| Press <2> to insert an element at a position in the array    ||
|| Press <3> to search an element in the array                  ||
|| Press <4> to delete an element from the array                ||
|| Press <5> to display the array                               ||
|| Press <0> to exit                                            ||
------------------------------------------------------------------
Enter choice: 4

Enter the value to delete: 30

After deletion...
1
20
3
4
5

------------------------------------------------------------------
|| Press <1> to update at a position in the array               ||
|| Press <2> to insert an element at a position in the array    ||
|| Press <3> to search an element in the array                  ||
|| Press <4> to delete an element from the array                ||
|| Press <5> to display the array                               ||
|| Press <0> to exit                                            ||
------------------------------------------------------------------
Enter choice: 5

Current array...
1
20
3
4
5

------------------------------------------------------------------
|| Press <1> to update at a position in the array               ||
|| Press <2> to insert an element at a position in the array    ||
|| Press <3> to search an element in the array                  ||
|| Press <4> to delete an element from the array                ||
|| Press <5> to display the array                               ||
|| Press <0> to exit                                            ||
------------------------------------------------------------------
Enter choice: 0
 * 
 * 
 */
/*//////////////////////////////////////////////*/
