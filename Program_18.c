/*A program to search a value in an array using Linear Search method*/

#include <stdio.h>

int linearSearch(int *array, int n, int target)
{
	int i;
	for(i=0;i<=n-1;i++)
	    if(array[i]==target)
	        return i;
	return -1;
}

int main()
{
    int n,i,j,item,index;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int arr[n];
	puts("\nEnter array elements");
	for(i=0;i<=n-1;i++)
	    scanf("%d",&arr[i]);
	printf("\nEnter the value to search: ");
	scanf("%d",&item);

	index=linearSearch(arr,n,item);
	
	if(index!=-1)
		printf("\n%d present in position: %d",item,index+1);
	else
		printf("\n%d not present in the array...",item);

    return 0;
}
/*
Enter the size of the array: 4

Enter array elements
5 6 7 1

Enter the value to search: 7

7 present in position: 3
////////////////////////////////////////
Enter the size of the array: 4

Enter array elements
5 6 7 1

Enter the value to search: 7

7 present in position: 3
*/