/*A program to search an item in a given array using Iterative and Recursive Binary Search*/

#include <stdio.h>
#include <stdlib.h>

int iterative_binarySearch(int *array, int n, int target)
{
	int i,low,mid,high;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(array[mid]==target)
			return mid;
		else if(array[mid]>target)
			high=mid-1;
		else
			low=mid+1;
	}
	
	return -1;
}

int recursive_binarySearch(int *array, int low, int high, int target)
{
	int mid;
	if(low<=high)
	{
		mid=low+(high-low)/2;
		if(array[mid]==target)
			return mid;
		else if(array[mid]>target)
			return recursive_binarySearch(array,low,mid-1,target);
		else
			return recursive_binarySearch(array,mid+1,high,target);
	}
	
	return -1;
}

int main()
{
	int i,n,item,choice,index;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int arr[n];
	puts("\nEnter array elements");
	for(i=0;i<=n-1;i++)
	    scanf("%d",&arr[i]);
	do
	{
		printf("Enter the value to search: ");
		scanf("%d",&item);
		printf("\n--------------------------------------------------------------------");
		printf("\n|| Press <1> to use the Binary Search Algorithm in Iterative way  ||");
		printf("\n|| Press <2> to use the Binary Search Algorithm in Recursive way  ||");
		printf("\n|| Press <0> to exit                                              ||");
		printf("\n--------------------------------------------------------------------");
		printf("\nEnter Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: exit(0);
			case 1: index=iterative_binarySearch(arr,n,item);
					break;
			case 2: index=recursive_binarySearch(arr,0,n-1,item);
					break;
			default: printf("\nEnter a valid choice...");
		}
	
		if(index!=-1)
			printf("\n%d present in position: %d\n",item,index+1);
		else
			printf("\n%d not present in the array...\n",item);
	}
	while(choice!=0);

	return 0;
}
/*
Enter the size of the array: 5

Enter array elements
1 2 3 4 5
Enter the value to search: 2

--------------------------------------------------------------------
|| Press <1> to use the Binary Search Algorithm in Iterative way  ||
|| Press <2> to use the Binary Search Algorithm in Recursive way  ||
|| Press <0> to exit                                              ||
--------------------------------------------------------------------
Enter Choice: 1

2 present in position: 2
Enter the value to search: 3

--------------------------------------------------------------------
|| Press <1> to use the Binary Search Algorithm in Iterative way  ||
|| Press <2> to use the Binary Search Algorithm in Recursive way  ||
|| Press <0> to exit                                              ||
--------------------------------------------------------------------
Enter Choice: 2

3 present in position: 3
Enter the value to search: 0

--------------------------------------------------------------------
|| Press <1> to use the Binary Search Algorithm in Iterative way  ||
|| Press <2> to use the Binary Search Algorithm in Recursive way  ||
|| Press <0> to exit                                              ||
--------------------------------------------------------------------
Enter Choice: 0
*/