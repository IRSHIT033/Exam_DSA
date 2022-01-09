/*A program to solve of the Tower of Hanoi problem*/

#include <stdio.h>
#include <math.h>

void towerofhanoi(int n, char source, char temp, char destination)
{
    if(n==1)
    {
        printf("\nDisk %d: %c ---> %c",n,source,destination);
        return;
    }
    towerofhanoi(n-1,source,destination,temp);
    printf("\nDisk %d: %c ---> %c",n,source,destination);    
    towerofhanoi(n-1,temp,source,destination);

}

int main()
{
    int n;
    char source='A', temp='B', destination='C';
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    if(n<0)
    	printf("\nPlease enter a positive no. of disks...");
    else
    {
	    printf("\nSequence is...\n");
	    towerofhanoi(n,source,temp,destination);
	    printf("\nTotal no. of moves required: %d",(int)(pow(2,n)-1));
	}

    return 0;
}
/**
 * Enter the number of disks: 3

Sequence is...

Disk 1: A ---> C
Disk 2: A ---> B
Disk 1: C ---> B
Disk 3: A ---> C
Disk 1: B ---> A
Disk 2: B ---> C
Disk 1: A ---> C
Total no. of moves required: 7
 * 
 */