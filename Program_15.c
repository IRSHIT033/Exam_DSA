/*A program to sort an array using Radix Sort method*/

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

void countingSort(int *array, int n, int power)
{
    int i;
    int output[n];
    int count[10];
    for(i=0;i<10;i++)
        count[i]=0;
    for(i=0;i<=n-1;i++)
        count[(array[i]/power)%10]++;
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[count[(array[i]/power)%10]-1]=array[i];
        count[(array[i]/power)%10]--;
    }
    for(i=0;i<=n-1;i++)
        array[i]=output[i];
}

void radixSort(int *array, int n)
{
    int power,maximum;
    maximum=max(array,n);
    power=1;
    while(maximum/power>0)
    {
        countingSort(array,n,power);
        power*=10;
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
	
    radixSort(arr,n);

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
10001 22333 34 56 77   

Before sorting...
10001
22333
34
56
77

After sorting (Ascending Order)...
34
56
77
10001
22333

After sorting (Descending Order)...
22333
10001
77
56
34
*/