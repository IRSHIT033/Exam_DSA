/*A program to count the frequency of each distinct character in a given string*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* count_frequency(char *str)
{
    int i,n,index;
    n=strlen(str);
    static int count[26];
	for(i=0;i<=25;i++)
        count[i]=0;
    for(i=0;i<=n-1;i++)
    {
        if(str[i]>=65 && str[i]<=90)
        {
            index=str[i]-'A';
            count[index]+=1;
        }
        else if(str[i]>=97 && str[i]<=122)
        {
            index=str[i]-'a';
            count[index]+=1;
        }
    }

    return count;
}

int main()
{
    int i;
    int *count;
    char str[100];
	printf("Enter a string: ");
    gets(str);
	
    count=count_frequency(str);

	printf("\nFrequencies of the characters in %s...\n",str);
	for(i=0;i<=25;i++)
        if(count[i]!=0)
	        printf("%c: %d\n",i+'a',count[i]);
	    
	return 0;
}
/*
Enter a string: irshit

Frequencies of the characters in irshit...
h: 1
i: 2
r: 1
s: 1
t: 1
*/