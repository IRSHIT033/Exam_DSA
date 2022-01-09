/*A program to insert an item in a given sorted array*/

#include <stdio.h>

void insert(int *array, int n, int value)
{
	int i=n-1;
	while(i>=0 && array[i]>value)
	{
		array[i+1]=array[i];
		i--;
	}
	array[i+1]=value;
}

int main()
{
    int n,i,val;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
    int arr[n];
	puts("\nEnter array elements in a sorted manner in Ascending Order");
	for(i=0;i<=n-1;i++)
	    scanf("%d",&arr[i]);
    printf("\nEnter the value to insert: ");
    scanf("%d",&val);
	
    insert(arr,n,val);

	puts("\nAfter insertion...");
	for(i=0;i<=n;i++)
	    printf("%d\n",arr[i]);
	    
	return 0;
}
/*
Enter the size of the array: 3

Enter array elements in a sorted manner in Ascending Order
1 4 6

Enter the value to insert: 2

After insertion...
1
2
4
6
*/