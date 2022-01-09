/*A program to sort an array using Quick Sort method*/

#include <stdio.h>

void swap(int *num1, int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}

int partition(int *array, int low, int high)
{
    int i,j,pivot;
    i=low;
    j=high+1;
    pivot=array[low];
    while(i<j)
    {
        do
        {
            i+=1;
        }while(i<=high && array[i]<=pivot);
        do
        {
            j-=1;
        }while(array[j]>pivot);
        if(i<j)
            swap(&array[i],&array[j]);
    }
    swap(&array[j],&array[low]);
    
    return j;
}

void quickSort(int *array, int low, int high)
{
    int i;
    if(low<high)
    {
        i=partition(array,low,high);
        quickSort(array,low,i-1);
        quickSort(array,i+1,high);
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

    quickSort(arr,0,n-1);

	puts("\nAfter sorting (Ascending Order)...");
	for(i=0;i<=n-1;i++)
	    printf("%d\n",arr[i]);
	puts("\nAfter sorting (Descending Order)...");
	for(i=n-1;i>=0;i--)
	    printf("%d\n",arr[i]);

    return 0;
}
/*
Enter the size of the array: 7

Enter array elements
8 9 1 2 4 6 7

Before sorting...
8
9
1
2
4
6
7

After sorting (Ascending Order)...
1
2
4
6
7
8
9

After sorting (Descending Order)...
9
8
7
6
4
2
1*/