/*A program to sort an array using Insertion Sort method*/

#include <stdio.h>

void insertionSort(int *array, int n)
{
	int i,j,temp;
	for(i=1;i<=n-1;i++)
	{
		j=i-1;
		temp=array[i];
		while(j>=0 && array[j]>temp)
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=temp;
	}
}

int main()
{
    int n,i;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int arr[n];
	puts("\nEnter array elements");
	for(i=0;i<=n-1;i++)
	    scanf("%d",&arr[i]);
	puts("\nBefore sorting...");
	for(i=0;i<=n-1;i++)
	    printf("%d\n",arr[i]);
	
    insertionSort(arr,n);

	puts("\nAfter sorting (Ascending Order)...");
	for(i=0;i<=n-1;i++)
	    printf("%d\n",arr[i]);
	puts("\nAfter sorting (Descending Order)...");
	for(i=n-1;i>=0;i--)
	    printf("%d\n",arr[i]);
	    
	return 0;
}
/*
Enter the size of the array: 4

Enter array elements
56 67 89 1  

Before sorting...
56
67
89
1

After sorting (Ascending Order)...
1
56
67
89

After sorting (Descending Order)...
89
67
56
1
*/