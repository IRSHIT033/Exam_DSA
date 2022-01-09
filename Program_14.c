/*A program to sort an array using Counting Sort method*/

#include <stdio.h>

int max(int *array, int n)
{
    int i,maximum;
    maximum=array[0];
    for(i=1;i<=n-1;i++)
        if(array[i]>maximum)
            maximum=array[i];

    return maximum;
}

void countingSort(int *array, int n)
{
    int i,maximum;
    maximum=max(array,n);
    int output[n],count[maximum+1];
    for(i=0;i<=maximum;i++)
        count[i]=0;
    for(i=0;i<=n-1;i++)
        count[array[i]]++;
    for(i=1;i<=maximum;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[count[array[i]]-1]=array[i];
        count[array[i]]--;
    }
    for(i=0;i<=n-1;i++)
        array[i]=output[i];
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
	
    countingSort(arr,n);

	puts("\nAfter sorting (Ascending Order)...");
	for(i=0;i<=n-1;i++)
	    printf("%d\n",arr[i]);
	puts("\nAfter sorting (Descending Order)...");
	for(i=n-1;i>=0;i--)
	    printf("%d\n",arr[i]);
	    
	return 0;
}
/*
Enter the size of the array: 5       

Enter array elements
1 8 3 4 2

Before sorting...
1
8
3
4
2

After sorting (Ascending Order)...
1
2
3
4
8

After sorting (Descending Order)...
8
4
3
2
1
*/