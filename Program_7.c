/*A program to find the nth Fibonacci number using tail recursion.*/

#include <stdio.h>

int fibonacci(int n, int a, int b)
{
    if(n==0)
        return a;
    if(n==1)
        return b;

    return fibonacci(n-1,b,a+b);
}

int main()
{
    int i,n,num1=0,num2=1;
    printf("Enter the position of term to print: ");
    scanf("%d",&n);
    printf("\n%dth term in the Fibonacci series: %d",n,fibonacci(n,num1,num2));

    return 0;
}
/**
 * Enter the position of term to print: 3

3th term in the Fibonacci series: 2
 * 
 */