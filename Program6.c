/*A program to find the factorial of a number using tail recursion*/

#include <stdio.h>

long long int factorial(int n, int prod)
{
    if(n==0)
        return prod;
    else
        return factorial(n-1,n*prod);
}

int main()
{
	int num,n;
	printf("Enter a number: ");
	scanf("%d",&num);
	if(num<0)
        printf("\n!!! Factorial of a negative number doesn't exist !!!");
    else
	    printf("\nThe Factorial of %d: %lld",num,factorial(num,1));
	
	return 0;
}
/*
Enter a number: 4

The Factorial of 4: 24
*/
