/*A program to sort an array using Selection Sort method*/

#include <stdio.h>

void selectionSort(int *array, int n)
{
	int i,j,k,temp,min;
	for(i=0;i<=n-1;i++)
	{
		min=array[i];
        k=i;
        for(j=i+1;j<=n-1;j++)
            if(min>array[j])
			{
                min=array[j];
                k=j;
            }
        if(i!=k)
		{
            temp=array[i];
            array[i]=array[k];
            array[k]=temp;
        } 
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
	
    selectionSort(arr,n);

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
2 5 1 7

Before sorting...
2
5
1
7

After sorting (Ascending Order)...
1
2
5
7

After sorting (Descending Order)...
7
5
2
1*/