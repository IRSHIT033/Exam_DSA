/*A program to add two polynomials using array*/

#include <stdio.h>
#include <stdlib.h>

int addpoly(int *poly1, int m, int *poly2, int n, int *res_poly, int p)
{
    int i,j;
	for(i=0;i<=m-1;i++)
		*(res_poly+i)=*(poly1+i);
	for(j=0;j<=n-1;j++)
		*(res_poly+j)=*(res_poly+j)+*(poly2+j);
}

int max(int a, int b)
{
	if(a>b)
	    return a;
	else
	    return b;
}

void print_poly(int *poly, int x)
{
    int i;
    int flag=0;
    for(i=0;i<=x-1;i++)
	{
        if(i<x-1)
        {
            if(*(poly+i)==0)
                continue;
            else
            {
                if(flag==0)
                {
                    printf("%dx^(%d) ",*(poly+i),i);
                    flag=flag+1;
                }
                else
                    printf("+ %dx^(%d)",*(poly+i),i);	
            }
        }
        else
        {
            if(*(poly+i)==0)
                break;
            else
            {
                if(flag==0)
                {
                    printf("%dx^(%d) ",*(poly+i),i);
                    flag=flag+1;
                }
                else
                    printf("+ %dx^(%d)",*(poly+i),i);
            }
        }
    }
}

int main()
{
	int *poly1,*poly2,*res_poly,m,n,p;
    int i;
    int flag;
	printf("\nEnter the highest power of x in first polynomial equation: ");
    scanf("%d",&m);
    printf("\nEnter the highest power of x in second polynomial equation: ");
    scanf("%d",&n);

	poly1=(int*)malloc(m*sizeof(int));
	poly2=(int*)malloc(n*sizeof(int));
	
    puts("\n*** For first polynomial equation ***\n");
    for(i=0;i<=m-1;i++)
    {
        printf("Enter co-efficient of x^%d: ",i);
        scanf("%d",(poly1+i));
    }
    puts("\n*** For second polynomial equation ***\n");
    for(i=0;i<=n-1;i++)
    {
        printf("Enter co-efficient of x^%d: ",i);
        scanf("%d",(poly2+i));
    }
	p=max(m,n);
	res_poly=(int*)calloc(p,sizeof(int));

	addpoly(poly1,m,poly2,n,res_poly,p);

    printf("\nFirst polynomial equation: ");
    print_poly(poly1,m);
    printf("\nSecond polynomial equation: ");
    print_poly(poly2,n);
    puts("\n\nAfter adding two polynomial equations...");
    print_poly(res_poly,p);
	
	return 0;
}
