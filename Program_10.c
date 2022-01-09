/*A program to sort an array using Bubble Sort method*/

#include <stdio.h>

void swap(int *num1, int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}

void bubbleSort(int *array, int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	    for(j=0;j<(n-i-1);j++)
	        if(array[j]>array[j+1])
				swap(&array[j],&array[j+1]);
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

    bubbleSort(arr,n);

    puts("\nAfter sorting (Ascending Order)...");
	for(i=0;i<=n-1;i++)
	    printf("%d\n",arr[i]);
	puts("\nAfter sorting (Descending Order)...");
	for(i=n-1;i>=0;i--)
	    printf("%d\n",arr[i]);

    return 0;
}
/*Enter the size of the array: 4

Enter array elements
6 1 4 90

Before sorting...
6
1
4
90

After sorting (Ascending Order)...
1
4
6
90

After sorting (Descending Order)...
90
6
4
1*/